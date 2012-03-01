#ifndef PIRFAVORITESFORM_H
#define PIRFAVORITESFORM_H

#include <QWidget>

class MainWindow;
//class PIRKeysetManager;
class PIRKeysetWidgetItem;
class QListWidget;

namespace Ui {
class PIRFavoritesForm;
}

class PIRFavoritesForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRFavoritesForm(QWidget *parent = 0);
  PIRFavoritesForm(
    MainWindow *mw);

  ~PIRFavoritesForm();

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

  void addItem(
    PIRKeysetWidgetItem *item);

  QListWidget *getFavoritesListWidget();

private slots:
  void on_addKeysetButton_clicked();
  void on_removeKeysetButton_clicked();
  
private:
  Ui::PIRFavoritesForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRFAVORITESFORM_H
