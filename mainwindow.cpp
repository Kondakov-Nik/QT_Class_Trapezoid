// Вычисление объёма куба и площади его боковой поверхности
// @author Кондакаков Н.С.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


// конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)  // явный вызов конструктора базового класса
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Объект ui содержит все классы-элементы интерфейса,
    // расположенные на главном окне.
    // класс для ui генерируется автоматически из дизайна окна
    ui->plainTextEdit->setReadOnly( !ui->plainTextEdit->isReadOnly() ); // запретить редактирование в PlainText
}

// Деструктор удаления объекта окна
MainWindow::~MainWindow()
{
    delete ui;
}

// обработчик события -- клик на кнопку
// обработчик создан в дизайнере форм
// кнопка вычисления
void MainWindow::on_Button_calc_clicked()
{
    try {
        t.setA( ui->lineEdit_vvod->text().toFloat());  // Обращение к содержимому поля ввода

        ui->label_result_V->setText( QString::number( t.v_kub())); // Перевод в строку и вывод результата на форму
        ui->label_result_S->setText( QString::number( t.s_kub())); // Перевод в строку и вывод результата на форму
        ui->lineEdit_vvod->setStyleSheet("background-color: white;");
        ui->plainTextEdit->appendPlainText( "Объем куба = " +QString::number(t.v_kub()) + "; Площадь боковой поверхности куба = " +
                                                                       QString::number(t.s_kub())); // Перевод в строку и вывод результата в PlainText

    }    catch (const std::invalid_argument &e) { // при неверно введеных данных появляется error
//         ui->statusbar->showMessage( "Error" );
         ui->lineEdit_vvod->setStyleSheet("background-color:rgb(250, 103, 103);"); // при неверно введеных данных поле ввода покрасится в красный
         ui->plainTextEdit->appendPlainText( "Неверно введенные данные"); // при неверно введеных данных в PlainText появится ошибка
//       QMessageBox::about(this, "Erorr", "Ошибка");
    }

//   {    ui->lineEdit_vvod->clear(); // очистить поле ввода
//    }

}

void MainWindow::on_about_author_triggered() // обработчки меню( о авторе)
{
    QMessageBox::about(this, "Об авторе", "Автор: Кондаков Никита Сергеевич");
}


void MainWindow::on_pushButton_clear_clicked() // очистить текст в таблице и лейблах
{
  ui->plainTextEdit->clear();
  ui->label_result_V->clear();
  ui->label_result_S->clear();
}

