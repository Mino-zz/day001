#include <gtk/gtk.h>
GtkWidget * label_man;
GtkWidget * label_et;
GtkWidget * label_vs;
void haha(GtkButton * button,gpointer user_data)
{
	const gchar * text =gtk_button_get_label(button);
	gtk_label_set_text(GTK_LABEL(label_man),text);

	srand(time(NULL));
	int a = rand()%3;
	switch(a)
	{
		case 0:
		gtk_label_set_text(GTK_LABEL(label_et),"石头");
		break;
		case 1:
		gtk_label_set_text(GTK_LABEL(label_et),"剪刀");
		break;
		case 2:
		gtk_label_set_text(GTK_LABEL(label_et),"布儿");
		break;
	}

	int b = (int)user_data;

	if(a==0 && b==2)
	{
		gtk_label_set_text(GTK_LABEL(label_vs),">>");
	}
	else if(a==2 && b==0)
	{
		gtk_label_set_text(GTK_LABEL(label_vs),"<<");
	}
	else if(a>b)
	{
		gtk_label_set_text(GTK_LABEL(label_vs),">>");
	}
	else if(a<b)
	{
		gtk_label_set_text(GTK_LABEL(label_vs),"<<");
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(label_vs),"==");
	}
}
int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_set_size_request(window,600,600);
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * vbox = gtk_vbox_new(TRUE,10);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	GtkWidget * label = gtk_label_new("成都理工猜拳游戏");
	gtk_container_add(GTK_CONTAINER(vbox),label);
	
    GtkWidget * label_info = gtk_label_new("我自己     大战      外星人");
	gtk_container_add(GTK_CONTAINER(vbox),label_info);

	GtkWidget * hbox = gtk_hbox_new(TRUE,10);
	gtk_container_add(GTK_CONTAINER(vbox),hbox);

	label_man = gtk_label_new("我自己");
	label_vs = gtk_label_new("vs");
	label_et = gtk_label_new("外星人");
	
	gtk_container_add(GTK_CONTAINER(hbox),label_man);
	gtk_container_add(GTK_CONTAINER(hbox),label_vs);
	gtk_container_add(GTK_CONTAINER(hbox),label_et);


	GtkWidget * hbox01 = gtk_hbox_new(TRUE,10);
	gtk_container_add(GTK_CONTAINER(vbox),hbox01);

	GtkWidget * button01 = gtk_button_new_with_label("石头");
	GtkWidget * button02 = gtk_button_new_with_label("剪刀");
	GtkWidget * button03 = gtk_button_new_with_label("布儿");
	
	gtk_container_add(GTK_CONTAINER(hbox01),button01);
	gtk_container_add(GTK_CONTAINER(hbox01),button02);
	gtk_container_add(GTK_CONTAINER(hbox01),button03);



	g_signal_connect(button01,"pressed",G_CALLBACK(haha),(gpointer)0);
	g_signal_connect(button02,"pressed",G_CALLBACK(haha),(gpointer)1);
	g_signal_connect(button03,"pressed",G_CALLBACK(haha),(gpointer)2);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}