#ifndef SERVERGUIMAINWINDOW_HPP
#define SERVERGUIMAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class ServerGuiMainWindow;
}

class ServerGuiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerGuiMainWindow(QWidget *parent = 0);
    ~ServerGuiMainWindow();

private:
    Ui::ServerGuiMainWindow *ui;
};

#endif // SERVERGUIMAINWINDOW_HPP
