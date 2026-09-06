/*
 * LDeskflow -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2026 LUODA
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#pragma once

#include <QPalette>
#include <QString>

namespace deskflow::gui::theme {

/**
 * @brief Builds the brand palette for the requested color scheme.
 * @param dark Whether the dark scheme is requested.
 */
QPalette palette(bool dark);

/**
 * @brief Loads the brand stylesheet (QSS) for the requested color scheme.
 * @param dark Whether the dark scheme is requested.
 */
QString stylesheet(bool dark);

/**
 * @brief Applies the brand palette and stylesheet to the whole application.
 * @param dark Whether the dark scheme is requested.
 */
void apply(bool dark);

} // namespace deskflow::gui::theme
