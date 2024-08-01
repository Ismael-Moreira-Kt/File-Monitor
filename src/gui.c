#include "gui.h"
#include "file_reader.h"
#include "logger.h"


#define BUFFER_SIZE 1024



static GtkWidget *window;
static GtkWidget *text_view;
static GtkWidget *open_button;
static GtkWidget *file_chooser;



static void on_open_button_clicked(GtkWidget *widget, gpointer data) {
    GtkFileChooser *chooser = GTK_FILE_CHOOSER(file_chooser);
    gchar *filename = gtk_file_chooser_get_filename(chooser);
    
    if (filename) {
        log_info("Attempting to open file", 23);
        
        int fd = open(filename, O_RDONLY);
        if (fd < 0) {
            log_error("Failed to open file");
            g_free(filename);
            return;
        }
        
        log_info("File opened successfully", 24);

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        GtkTextBuffer *text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        gtk_text_buffer_set_text(text_buffer, "", -1);

        while ((bytes_read = read_from_file(fd, buffer, sizeof(buffer))) > 0) {
            gtk_text_buffer_insert_at_cursor(text_buffer, buffer, bytes_read);
        }

        if (bytes_read < 0) {
            log_error("Error reading from file");
        } else {
            log_info("File read successfully", 23);
        }

        close(fd);
        g_free(filename);
    } else {
        log_error("No file selected");
    }
}



void create_gui() {
    GtkWidget *vbox;
    GtkWidget *scroll_window;

    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "File Monitor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    open_button = gtk_button_new_with_label("Open File");
    g_signal_connect(open_button, "clicked", G_CALLBACK(on_open_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), open_button, FALSE, FALSE, 0);

    file_chooser = gtk_file_chooser_button_new("Select a File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_box_pack_start(GTK_BOX(vbox), file_chooser, FALSE, FALSE, 0);

    scroll_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(vbox), scroll_window, TRUE, TRUE, 0);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scroll_window), text_view);

    gtk_widget_show_all(window);
    gtk_main();
}