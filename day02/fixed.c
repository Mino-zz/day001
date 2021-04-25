#include <gtk/gtk.h>

GtkWidget * label;
GtkWidget * entry;
void haha(GtkButton * button,gpointer user_data)
{
	const gchar * text1 = gtk_label_get_text(GTK_LABEL(label));
	printf("%s\n",text1);
	const gchar * text = gtk_entry_get_text(GTK_ENTRY(entry));

	gtk_label_set_text(GTK_LABEL(label),text);

	gtk_entry_set_text(GTK_ENTRY(entry),"");
	
}

void load_image(GtkWidget *image, const char *file_path, const int w, const int h )
{
    gtk_image_clear( GTK_IMAGE(image) ); // 清除图像
    GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(file_path, NULL); // 创建图片资源
    GdkPixbuf *dest_pixbuf=gdk_pixbuf_scale_simple(src_pixbuf,w,h,GDK_INTERP_BILINEAR); // 指定大小
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), dest_pixbuf); // 图片控件重新设置一张图片(pixbuf)
    g_object_unref(src_pixbuf); // 释放资源
    g_object_unref(dest_pixbuf); // 释放资源
}

int sungtk_widget_set_font_size(GtkWidget *widget, int size, gboolean is_button)
{
	GtkWidget *labelChild;  
	PangoFontDescription *font;  
	gint fontSize = size;  
	if(widget == NULL)
		return -1;
  
	font = pango_font_description_from_string("Sans");          //"Sans"字体名   
	pango_font_description_set_size(font, fontSize*PANGO_SCALE);//设置字体大小   
	
	if(is_button){
		labelChild = gtk_bin_get_child(GTK_BIN(widget));//取出GtkButton里的label  
	}else{
		labelChild = widget;
	}
	
	//设置label的字体，这样这个GtkButton上面显示的字体就变了
	gtk_widget_modify_font(GTK_WIDGET(labelChild), font);
	pango_font_description_free(font);

	return 0;
}

int sungtk_color_get(const char *color_buf, GdkColor *color)
{
	gdk_color_parse(color_buf, color);
	return 0;
}

int sungtk_widget_set_font_color(GtkWidget *widget, const char *color_buf, gboolean is_button)
{
	if(widget == NULL && color_buf==NULL)
		return -1;
	
	GdkColor color;
	GtkWidget *labelChild = NULL;
	sungtk_color_get(color_buf, &color);
	if(is_button == TRUE){
		labelChild = gtk_bin_get_child(GTK_BIN(widget));//取出GtkButton里的label  
		gtk_widget_modify_fg(labelChild, GTK_STATE_NORMAL, &color);
		gtk_widget_modify_fg(labelChild, GTK_STATE_SELECTED, &color);
		gtk_widget_modify_fg(labelChild, GTK_STATE_PRELIGHT, &color);
	}else{
		gtk_widget_modify_fg(widget, GTK_STATE_NORMAL, &color);
	}
	return 0;
}


int main (int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget * window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_set_size_request(window,400,450);



	GtkWidget * fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window),fixed);

	GtkWidget * image = gtk_image_new_from_pixbuf(NULL);
	load_image(image,"1.jpg",400,450);
	gtk_fixed_put(GTK_FIXED(fixed),image,0,0);


	GtkWidget * button = gtk_button_new_with_label("添加");
	gtk_widget_set_size_request(button,60,30);
	gtk_fixed_put(GTK_FIXED(fixed),button,180,210);



	label = gtk_label_new("请输入好友QQ号：");
	gtk_fixed_put(GTK_FIXED(fixed),label,50,140);

	sungtk_widget_set_font_size(label,11,FALSE);
	sungtk_widget_set_font_color(label,"#000000",FALSE);


	entry =gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed),entry,169,140);
	//sungtk_widget_set_font_size(entry,33,FALSE);



    g_signal_connect(button,"pressed",G_CALLBACK(haha),NULL);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}