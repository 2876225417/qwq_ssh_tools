#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    // 创建 QApplication 实例
    QApplication app(argc, argv);

    // 创建一个按钮
    QPushButton button("Hello, Qt6!");

    // 设置按钮点击时退出应用程序
    QObject::connect(&button, &QPushButton::clicked, &app, &QApplication::quit);

    // 显示按钮
    button.show();

    // 启动应用程序的事件循环
    return app.exec();
}
