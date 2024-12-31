#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow();
private:
    QWidget* central_widget;
    QVBoxLayout* layout;
    QLabel* label;
    QPushButton* button;

};
#endif  // MAINWINDOW_H_