#include <gtk/gtk.h>
#include <time.h>

gboolean cdExposeEvent(GtkWidget *widget_, gpointer user_data_);

int vel = 2;
int acc = 2;
int now_x = 50;
int now_y = 50;

int main(int argc, char *argv[]){
	GtkWidget *window;
	GtkWidget *canvas;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 400, 200);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	canvas = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), canvas);
	g_timeout_add(500, (GSourceFunc)cdExposeEvent, canvas);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

gboolean cdExposeEvent(GtkWidget *widget_, gpointer user_data_){
	GdkWindow *drawable = widget_ -> window;
	cairo_t *cr;

	cr = gdk_cairo_create(drawable);
	cairo_set_line_width(cr, 1.0f);

	cairo_set_source_rgb(cr, 0.0f, 0.0f, 0.0f);
	cairo_rectangle(cr, now_x-10.0f, now_y-10.0f, 20.0f, 20.0f);
	cairo_stroke(cr);

	cairo_destroy(cr);

	now_x += vel;
	now_y += 2;
	vel += acc / 2;

	return TRUE;
}
