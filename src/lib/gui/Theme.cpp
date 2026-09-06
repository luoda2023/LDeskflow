/*
 * LDeskflow -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2026 LUODA
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#include "Theme.h"

#include <QApplication>
#include <QColor>
#include <QFile>
#include <QPalette>

namespace deskflow::gui::theme {

QPalette palette(bool dark)
{
  QPalette p;

  if (dark) {
    p.setColor(QPalette::Window, QColor(0x1a, 0x1a, 0x22));
    p.setColor(QPalette::WindowText, QColor(0xed, 0xed, 0xf5));
    p.setColor(QPalette::Base, QColor(0x23, 0x23, 0x2f));
    p.setColor(QPalette::AlternateBase, QColor(0x2a, 0x2a, 0x38));
    p.setColor(QPalette::Text, QColor(0xed, 0xed, 0xf5));
    p.setColor(QPalette::PlaceholderText, QColor(0x9a, 0x9a, 0xb0));
    p.setColor(QPalette::Button, QColor(0x2a, 0x2a, 0x36));
    p.setColor(QPalette::ButtonText, QColor(0xed, 0xed, 0xf5));
    p.setColor(QPalette::BrightText, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::Highlight, QColor(0x8b, 0x7b, 0xe8));
    p.setColor(QPalette::HighlightedText, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::Link, QColor(0xa8, 0x9b, 0xff));
    p.setColor(QPalette::LinkVisited, QColor(0x8f, 0x83, 0xea));
    p.setColor(QPalette::ToolTipBase, QColor(0xf2, 0xf0, 0xfb));
    p.setColor(QPalette::ToolTipText, QColor(0x2a, 0x24, 0x38));
    p.setColor(QPalette::Disabled, QPalette::Text, QColor(0x62, 0x62, 0x7a));
    p.setColor(QPalette::Disabled, QPalette::WindowText, QColor(0x62, 0x62, 0x7a));
    p.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(0x62, 0x62, 0x7a));
    p.setColor(QPalette::Disabled, QPalette::Highlight, QColor(0x4c, 0x46, 0x70));
    p.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(0x9b, 0x95, 0xc9));
  } else {
    p.setColor(QPalette::Window, QColor(0xf6, 0xf6, 0xfb));
    p.setColor(QPalette::WindowText, QColor(0x19, 0x19, 0x24));
    p.setColor(QPalette::Base, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::AlternateBase, QColor(0xf0, 0xf0, 0xf7));
    p.setColor(QPalette::Text, QColor(0x19, 0x19, 0x24));
    p.setColor(QPalette::PlaceholderText, QColor(0x9a, 0x9a, 0xb0));
    p.setColor(QPalette::Button, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::ButtonText, QColor(0x19, 0x19, 0x24));
    p.setColor(QPalette::BrightText, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::Highlight, QColor(0x6c, 0x5c, 0xe7));
    p.setColor(QPalette::HighlightedText, QColor(0xff, 0xff, 0xff));
    p.setColor(QPalette::Link, QColor(0x6c, 0x5c, 0xe7));
    p.setColor(QPalette::LinkVisited, QColor(0x5a, 0x4b, 0xd0));
    p.setColor(QPalette::ToolTipBase, QColor(0x2a, 0x24, 0x38));
    p.setColor(QPalette::ToolTipText, QColor(0xf2, 0xf0, 0xfb));
    p.setColor(QPalette::Disabled, QPalette::Text, QColor(0xa9, 0xa9, 0xbb));
    p.setColor(QPalette::Disabled, QPalette::WindowText, QColor(0xa9, 0xa9, 0xbb));
    p.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(0xa9, 0xa9, 0xbb));
    p.setColor(QPalette::Disabled, QPalette::Highlight, QColor(0xc9, 0xc4, 0xec));
    p.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(0xf2, 0xf1, 0xfb));
  }

  return p;
}

QString stylesheet(bool dark)
{
  const auto path = dark ? QStringLiteral(":/themes/ldeskflow-dark.qss") : QStringLiteral(":/themes/ldeskflow-light.qss");
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return {};
  return QString::fromUtf8(file.readAll());
}

void apply(bool dark)
{
  // Kept deliberately simple: we leave the QPalette untouched so the app stays
  // fully responsive to live OS theme changes (Qt only pushes fresh platform
  // palettes to the application while the palette is not explicitly overridden).
  // The brand colors are applied through the stylesheet instead. `palette()` is
  // available for a future optional "custom accent" mode.
  auto *app = qobject_cast<QApplication *>(QCoreApplication::instance());
  if (app == nullptr)
    return;

  app->setStyleSheet(stylesheet(dark));
}

} // namespace deskflow::gui::theme
