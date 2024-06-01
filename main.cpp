#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class StudentDBApp : public QWidget {
public:
    StudentDBApp(QWidget *parent = 0);

private slots:
    void onAddStudent();
    void onViewStudents();
};

StudentDBApp::StudentDBApp(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *addStudentBtn = new QPushButton("Add Student", this);
    QPushButton *viewStudentsBtn = new QPushButton("View Students", this);

    connect(addStudentBtn, &QPushButton::clicked, this, &StudentDBApp::onAddStudent);
    connect(viewStudentsBtn, &QPushButton::clicked, this, &StudentDBApp::onViewStudents);

    layout->addWidget(addStudentBtn);
    layout->addWidget(viewStudentsBtn);

    setLayout(layout);
}

void StudentDBApp::onAddStudent() {
    // Add student logic
}

void StudentDBApp::onViewStudents() {
    // View students logic
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StudentDBApp window;
    window.resize(300, 200);
    window.setWindowTitle("Student Database Management System");
    window.show();

    return app.exec();
}
