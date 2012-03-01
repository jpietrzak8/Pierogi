#ifndef PIRADJUSTFORM_H
#define PIRADJUSTFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAdjustForm;
}

class PIRAdjustForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRAdjustForm(MainWindow *mw);
  ~PIRAdjustForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void bassUpEnabled(bool);
  void trebleUpEnabled(bool);
  void enhancedBassEnabled(bool);
  void noiseReductionEnabled(bool);
  void bassDownEnabled(bool);
  void trebleDownEnabled(bool);
  void balanceLeftEnabled(bool);
  void balanceRightEnabled(bool);
  void surroundEnabled(bool);
  void colorUpEnabled(bool);
  void brightnessUpEnabled(bool);
  void contrastUpEnabled(bool);
  void zoomEnabled(bool);
  void colorDownEnabled(bool);
  void brightnessDownEnabled(bool);
  void contrastDownEnabled(bool);

private slots:
  void on_bassUpButton_pressed();
  void on_bassUpButton_released();
  void on_trebleUpButton_pressed();
  void on_trebleUpButton_released();
  void on_enhancedBassButton_pressed();
  void on_enhancedBassButton_released();
  void on_noiseReductionButton_pressed();
  void on_noiseReductionButton_released();
  void on_bassDownButton_pressed();
  void on_bassDownButton_released();
  void on_trebleDownButton_pressed();
  void on_trebleDownButton_released();
  void on_balanceLeftButton_pressed();
  void on_balanceLeftButton_released();
  void on_balanceRightButton_pressed();
  void on_balanceRightButton_released();
  void on_colorUpButton_pressed();
  void on_colorUpButton_released();
  void on_brightnessUpButton_pressed();
  void on_brightnessUpButton_released();
  void on_contrastUpButton_pressed();
  void on_contrastUpButton_released();
  void on_colorDownButton_pressed();
  void on_colorDownButton_released();
  void on_brightnessDownButton_pressed();
  void on_brightnessDownButton_released();
  void on_contrastDownButton_pressed();
  void on_contrastDownButton_released();
  void on_surroundButton_pressed();
  void on_surroundButton_released();
  void on_zoomButton_pressed();
  void on_zoomButton_released();

private:
  Ui::PIRAdjustForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRADJUSTFORM_H
