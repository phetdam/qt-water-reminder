/**
 * @file alert.cc
 * @author Derek Huang <djh458@stern.nyu.edu>
 * @brief Implementation for the pomwr notification window.
 * @copyright MIT License
 */

#include "gui/alert.h"

#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtGui/QFont>
#include <QtGui/QPalette>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "gui/utils.h"

namespace pwr {

// WaterAlert size of window, size of buttons, and button font def, palette
const QSize WaterAlert::window_size_ = QSize(400, 150);
const QSize WaterAlert::button_size_ = QSize(71, 41);
const QFont WaterAlert::button_font_ = QFont(QString("Consolas"), 24);

/**
 * Overloaded constructor for the `WaterAlert` that accepts a `QPalette &`.
 * 
 * WaterAlert is an application-modal subclass of QDialog that manages its own
 * widget data, which we initialize in the constructor. The `WaterAlert` is
 * also capable of emitting its own signals through slot functions.
 * 
 * @param parent `QWidget` pointer to a parent widget.
 * @param palette `QPalette` reference to set the palette as. Defaults to
 *     whatever `QPalette` is returned by `pwr::BasePalette`.
 */
WaterAlert::WaterAlert(QWidget *parent, const QPalette &palette)
  : QDialog(parent)
{
  FixWidgetSize(*this, WaterAlert::window_size_);
  setPalette(palette);
  setModal(true);
  // init + format the "yes" button. button text is "hai" in hiragana. this is
  // a flat style button with red 24 pt Consolas text. note that since we set
  button_yes_ = new QPushButton(QString("\343\201\257\343\201\204"), this);
  button_yes_->setGeometry(QRect(QPoint(30, 90), WaterAlert::button_size_));
  button_yes_->setStyleSheet(QString("QPushButton {color: #00ff00}"));
  button_yes_->setFont(WaterAlert::button_font_);
  button_yes_->setFlat(true);
  // init + format the "no" button. button text is "ie" in hiragana. this is a
  // flat style button with green 24 pt Consolas text.
  button_no_ = new QPushButton(QString("\343\201\204\343\201\210"), this);
  button_no_->setGeometry(QRect(QPoint(300, 90), WaterAlert::button_size_));
  button_no_->setStyleSheet(QString("QPushButton {color: #ff0000}"));
  button_no_->setFont(WaterAlert::button_font_);
  button_no_->setFlat(true);
  // init + format the declarative label. font is auto size Consolas.
  label_decl_ = new QLabel("Pomu is telling you to drink your water!", this);
  label_decl_->setGeometry(QRect(10, 10, 291, 21));
  label_decl_->setFont(QFont("Consolas"));
  // init + format the prompt label. font is 12 pt Sans Serif bold.
  label_prompt_ = new QLabel("Will you drink your water?", this);
  label_prompt_->setGeometry(QRect(10, 40, 241, 21));
  label_prompt_->setFont(QFont("Sans Serif", 12, QFont::Bold));
}

/**
 * Overloaded constructor for the `WaterAlert`.
 * 
 * Uses the `QPalette` returned by `pwr::BasePalette`.
 * 
 * @param parent `QWidget` pointer to a parent widget.
 */
WaterAlert::WaterAlert(QWidget *parent) : WaterAlert(parent, BasePalette()) {}

/**
 * Default constructor for the `WaterAlert`.
 * 
 * No parent `QWidget` and uses the `QPalette` from `pwr::BasePalette`.
 */
WaterAlert::WaterAlert() : WaterAlert(nullptr) {}

/**
 * Getters for QWidgets managed by the WaterAlert.
 * 
 * These can all be used to access and modify the state of the private QWidgets
 * while internally storage duration is managed by std::unique_ptr instances.
 */
QPushButton *WaterAlert::button_yes() const { return button_yes_; }
QPushButton *WaterAlert::button_no() const { return button_no_; }
QLabel *WaterAlert::label_decl() const { return label_decl_; }
QLabel *WaterAlert::label_prompt() const { return label_prompt_; }

} // namespace pwr
