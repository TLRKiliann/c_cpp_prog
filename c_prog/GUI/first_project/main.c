#include <gtk/gtk.h>

// Déclaration globale du GtkBuilder
GtkBuilder *builder;

static void
print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}

static void
print_test (GtkWidget *widget, gpointer data)
{
  g_print ("Hello Test\n");
}

static void
display_input_text (GtkWidget *widget,
                    gpointer   data)
{
  const gchar *text;
  GtkWidget *entry = GTK_WIDGET(data);
  GtkWidget *label = GTK_WIDGET(gtk_builder_get_object(builder, "display_label"));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  gtk_label_set_text(GTK_LABEL(label), text);
  g_print ("Input Text: %s\n", text);
}

int main (int   argc, char *argv[])
{
 // GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GObject *entry;
  GObject *label; // Ajout de l'objet pour l'étiquette
  GError *error = NULL;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  label = gtk_builder_get_object (builder, "label0");
  gtk_label_set_text(GTK_LABEL(label), "Display in console");

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "testbtn");
  g_signal_connect (button, "clicked", G_CALLBACK (print_test), NULL);

  button = gtk_builder_get_object (builder, "quit");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  label = gtk_builder_get_object (builder, "label1");
  gtk_label_set_text(GTK_LABEL(label), "Label Text here");

  label = gtk_builder_get_object (builder, "label2");
  gtk_label_set_text(GTK_LABEL(label), "Label Text 2 here");

  // Ajout de l'entrée et du bouton
  entry = gtk_builder_get_object (builder, "entry1");
  button = gtk_builder_get_object (builder, "display_text_button");
  g_signal_connect (button, "clicked", G_CALLBACK (display_input_text), entry);

  gtk_main ();

  return 0;
}
