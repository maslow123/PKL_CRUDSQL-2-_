#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("teskonek");
    db.setUserName("root");
    db.setPassword("");

    if (db.open()){
        qDebug() << "Berhasil konek database";
    }
    else{
        qDebug() <<"Koneksi Gagal";
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_update_clicked()
{
    QString first,last,id;

        first = ui -> lineEdit_first -> text();
        last = ui -> lineEdit_last -> text();

    QSqlQuery query;
        query.prepare("UPDATE tes set firstname='"+first+"',lastname='"+last+"' where lastname='"+last+"'");
        if(query.exec()){
            QMessageBox msgBox;
            msgBox.setText("Data berhasil diubah , silahkan lihat database anda");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Data gagal diubah!");
            msgBox.exec();
        }

}

void MainWindow::on_pushButton_clear_clicked()
{
    ui -> lineEdit_first -> setText("");
    ui -> lineEdit_last -> setText("");
    ui -> lineEdit_id -> setText("");


}

void MainWindow::on_pushButton_insert_clicked()
{
    QString first,last;

        first = ui -> lineEdit_first -> text();
        last = ui -> lineEdit_last -> text();

    QSqlQuery query;
        query.prepare("INSERT INTO tes(firstname,lastname) VALUES ('"+first+"','"+last+"')");
        if(query.exec()){
            QMessageBox msgBox;
            msgBox.setText("Data berhasil ditambahkan , silahkan lihat database anda");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Data gagal ditambahkan !");
            msgBox.exec();
        }

}

void MainWindow::on_pushButton_delete_clicked()
{
    QString first,last,id;

        first = ui -> lineEdit_first -> text();
        last = ui -> lineEdit_last -> text();

    QSqlQuery query;
        query.prepare("DELETE FROM tes WHERE lastname='"+last+"' ");
        if(query.exec()){
            QMessageBox msgBox;
            msgBox.setText("Data berhasil dihapus , silahkan lihat database anda");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Data gagal dihapus!");
            msgBox.exec();
        }
}


