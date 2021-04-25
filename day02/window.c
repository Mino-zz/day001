#include <gtk/gtk.h>
void haha(GtkButton * button,gpointer user_data)
{
	//printf("woya\n");
	const gchar *text = gtk_button_get_label(button);
	               //局部变量，可获取的文本
	printf("%s\n",text);
}

//定义主函数，没有const
int main(int argc,char *argv[])
{
	//初始化，第一句写一次
	gtk_init(&argc,&argv);
	//创建窗口
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //控件    指针 变量名  gtk  窗口  新建  有边框
    //驼峰命名法
    //设置窗口属性
    //标题
    gtk_window_set_title(GTK_WINDOW(window),"卡哇伊");
    //                       给谁设置（窗口类型）
    //大小
    gtk_widget_set_size_request(window,520,520);

    //布局
    GtkWidget * hbox = gtk_vbox_new(TRUE,10);
    gtk_container_add(GTK_CONTAINER(window),hbox);
    //按钮
    //创建按钮
    GtkWidget * button01 = gtk_button_new_with_label("你戳我呀！");
    //           b变量         按钮            标签
    gtk_container_add(GTK_CONTAINER(hbox),button01);
    //   容器    添加      往哪添加（容器类型)
    //信号
    g_signal_connect(button01,"pressed",G_CALLBACK(haha),NULL);



    GtkWidget * button02 = gtk_button_new_with_label("你踢我呀！");   
    gtk_container_add(GTK_CONTAINER(hbox),button02); 
    g_signal_connect(button02,"pressed",G_CALLBACK(haha),NULL);



    GtkWidget * button03 = gtk_button_new_with_label("你打我呀！");   
    gtk_container_add(GTK_CONTAINER(hbox),button03); 
    g_signal_connect(button03,"pressed",G_CALLBACK(haha),NULL);
    


    //点叉退出程序
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    
    //显示窗口
    gtk_widget_show_all(window);
    //gtk 控件  显示 窗口
    gtk_main();
    //主事件循环
	return 0;

}