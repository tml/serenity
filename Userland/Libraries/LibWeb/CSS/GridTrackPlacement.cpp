/*
 * Copyright (c) 2022, Martin Falisse <mfalisse@outlook.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "GridTrackPlacement.h"
#include <AK/DeprecatedString.h>

namespace Web::CSS {

GridTrackPlacement::GridTrackPlacement(int span_count_or_position, bool has_span)
    : m_type(has_span ? Type::Span : Type::Position)
    , m_span_count_or_position(span_count_or_position)
{
}

GridTrackPlacement::GridTrackPlacement(DeprecatedString line_name, int span_count_or_position, bool has_span)
    : m_type(has_span ? Type::Span : Type::Position)
    , m_span_count_or_position(span_count_or_position)
    , m_line_name(line_name)
{
}

GridTrackPlacement::GridTrackPlacement(DeprecatedString line_name, bool has_span)
    : m_type(has_span ? Type::Span : Type::Position)
    , m_line_name(line_name)
{
}

GridTrackPlacement::GridTrackPlacement()
    : m_type(Type::Auto)
{
}

DeprecatedString GridTrackPlacement::to_deprecated_string() const
{
    StringBuilder builder;
    if (is_auto()) {
        builder.append("auto"sv);
        return builder.to_deprecated_string();
    }
    if (is_span()) {
        builder.append("span"sv);
        builder.append(" "sv);
    }
    if (m_span_count_or_position != 0) {
        builder.append(DeprecatedString::number(m_span_count_or_position));
        builder.append(" "sv);
    }
    if (has_line_name()) {
        builder.append(m_line_name);
    }
    return builder.to_deprecated_string();
}

}
