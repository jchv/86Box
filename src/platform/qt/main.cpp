#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    QMainWindow w;
    w.setWindowTitle("86Box");
    w.resize(640, 480);
    w.show();
    a.exec();
}
