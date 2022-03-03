/**
 * @file alert.h
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Header file defining the pomwr water reminder alert window.
 * @copyright MIT License
 * 
 * Modified from a header file generated by Qt Designer.
 */

#ifndef PWR_ALERT_H_
#define PWR_ALERT_H_

#include <memory>

#include <QtCore/QSize>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

namespace pwr {

class WaterAlert: public QDialog
{
public:
  WaterAlert();
  WaterAlert(const QPalette &);
  QPushButton &button_yes() const;
  QPushButton &button_no() const;
  QLabel &label_decl() const;
  QLabel &label_prompt() const;

private:
  static const QSize window_size_;
  static const QSize button_size_;
  static const QFont button_font_;
  std::unique_ptr<QPushButton> button_yes_;
  std::unique_ptr<QPushButton> button_no_;
  std::unique_ptr<QLabel> label_decl_;
  std::unique_ptr<QLabel> label_prompt_;
};

} // namespace pwr

#endif // PWR_ALERT_H_
