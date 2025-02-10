#include "calculator.h"

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <QVariant>

enum Operations {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

void number_button_clicked(QLabel * output, QString number_character) {
    output->setText(output->text() + number_character);
}

void operation_button_clicked(Operations * current_opp, QLabel * output, QString * previous_output, Operations new_opp) {
    *current_opp = new_opp;
    *previous_output = output->text();
    output->clear();
}

void equals_button_clicked(Operations * current_opp, QLabel * output, QString * previous_output) {
    if(previous_output->isEmpty())
    {
        return;
    }
    int num1, num2;
    switch(*current_opp) {
    case ADD:
        num1 = previous_output->toInt();
        num2 = output->text().toInt();
        output->setText(QVariant(num1 + num2).toString());
        break;
    case SUBTRACT:
        num1 = previous_output->toInt();
        num2 = output->text().toInt();
        output->setText(QVariant(num1 - num2).toString());
        break;
    case MULTIPLY:
        num1 = previous_output->toInt();
        num2 = output->text().toInt();
        output->setText(QVariant(num1 * num2).toString());
        break;
    case DIVIDE:
        num1 = previous_output->toInt();
        num2 = output->text().toInt();
        output->setText(QVariant(num1 / num2).toString());
        break;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    Operations current_opp{};
    QString previous_output{};

    //create main widget
    QWidget main_widget = QWidget();

    //Created the gird layout for the numpad and widget holder
    QGridLayout numpad = QGridLayout();
    QWidget numpad_holder = QWidget();
    //Create the vertical stack for the numpad and the display area
    QVBoxLayout main_stack = QVBoxLayout();

    //Create the label to store output
    QLabel output = QLabel();

    //Created the number buttons
    QPushButton button1 = QPushButton("0");
    QPushButton button2 = QPushButton("1");
    QPushButton button3 = QPushButton("2");
    QPushButton button4 = QPushButton("3");
    QPushButton button5 = QPushButton("4");
    QPushButton button6 = QPushButton("5");
    QPushButton button7 = QPushButton("6");
    QPushButton button8 = QPushButton("7");
    QPushButton button9 = QPushButton("8");
    QPushButton button10 = QPushButton("9");

    QPushButton add_button = QPushButton("+");
    QPushButton subtract_button = QPushButton("-");
    QPushButton multiply_button = QPushButton("*");
    QPushButton divide_button = QPushButton("/");

    QPushButton equals_button = QPushButton("=");

    QPushButton clear_button = QPushButton("Clear/Reset");


    //Connect number butttons to their function
    QObject::connect(&button1, &QPushButton::clicked, &button1, [&](){number_button_clicked(&output, button1.text());});
    QObject::connect(&button2, &QPushButton::clicked, &button2, [&](){number_button_clicked(&output, button2.text());});
    QObject::connect(&button3, &QPushButton::clicked, &button3, [&](){number_button_clicked(&output, button3.text());});
    QObject::connect(&button4, &QPushButton::clicked, &button4, [&](){number_button_clicked(&output, button4.text());});
    QObject::connect(&button5, &QPushButton::clicked, &button5, [&](){number_button_clicked(&output, button5.text());});
    QObject::connect(&button6, &QPushButton::clicked, &button6, [&](){number_button_clicked(&output, button6.text());});
    QObject::connect(&button7, &QPushButton::clicked, &button7, [&](){number_button_clicked(&output, button7.text());});
    QObject::connect(&button8, &QPushButton::clicked, &button8, [&](){number_button_clicked(&output, button8.text());});
    QObject::connect(&button9, &QPushButton::clicked, &button9, [&](){number_button_clicked(&output, button9.text());});
    QObject::connect(&button10, &QPushButton::clicked, &button10, [&](){number_button_clicked(&output, button10.text());});

    QObject::connect(&add_button, &QPushButton::clicked, &add_button, [&](){operation_button_clicked(&current_opp, &output, &previous_output, ADD);});
    QObject::connect(&subtract_button, &QPushButton::clicked, &subtract_button, [&](){operation_button_clicked(&current_opp, &output, &previous_output, SUBTRACT);});
    QObject::connect(&multiply_button, &QPushButton::clicked, &multiply_button, [&](){operation_button_clicked(&current_opp, &output, &previous_output, MULTIPLY);});
    QObject::connect(&divide_button, &QPushButton::clicked, &divide_button, [&](){operation_button_clicked(&current_opp, &output, &previous_output, DIVIDE);});
    QObject::connect(&equals_button, &QPushButton::clicked, &equals_button, [&](){equals_button_clicked(&current_opp, &output, &previous_output);});

    //add number buttons to numpad
    numpad.addWidget(&button1, 3, 1);
    numpad.addWidget(&button2, 0, 0);
    numpad.addWidget(&button3, 0, 1);
    numpad.addWidget(&button4, 0, 2);
    numpad.addWidget(&button5, 1, 0);
    numpad.addWidget(&button6, 1, 1);
    numpad.addWidget(&button7, 1, 2);
    numpad.addWidget(&button8, 2, 0);
    numpad.addWidget(&button9, 2, 1);
    numpad.addWidget(&button10, 2, 2);

    numpad.addWidget(&add_button, 0, 3);
    numpad.addWidget(&subtract_button, 1, 3);
    numpad.addWidget(&multiply_button, 2, 3);
    numpad.addWidget(&divide_button, 3, 3);

    numpad.addWidget(&equals_button, 4, 3);

    numpad_holder.setLayout(&numpad);

    main_stack.addWidget(&output);
    main_stack.addWidget(&numpad_holder);


    //set layout of main widget
    main_widget.setLayout(&main_stack);


    //set central widget and show app window
    w.setCentralWidget(&main_widget);
    w.show();

    return a.exec();


}
