#ifndef FOURTHANDFIVE_VIEW_H
#define FOURTHANDFIVE_VIEW_H

#include <array>
#include <cstddef>

namespace fourthandfive {

template<std::size_t C, std::size_t R>
struct View {
    std::array<char, (C * R)> buffer;
    std::size_t nCols{C};
    std::size_t nRows{R};
};

inline constexpr std::size_t k_FIELD_VIEW_COLS = 121uz;
inline constexpr std::size_t k_FIELD_VIEW_ROWS = 7uz;
inline constexpr View<k_FIELD_VIEW_COLS, k_FIELD_VIEW_ROWS> createDefaultFieldView() {
    return View<k_FIELD_VIEW_COLS, k_FIELD_VIEW_ROWS>{};
}

inline constexpr std::size_t k_INPUT_VIEW_COLS = 5uz;
inline constexpr std::size_t k_INPUT_VIEW_ROWS = 1uz;
inline constexpr View<k_INPUT_VIEW_COLS, k_INPUT_VIEW_ROWS> createDefaultInputView() {
    return View<k_INPUT_VIEW_COLS, k_INPUT_VIEW_ROWS>{};
}

} // close namespace fourthandfive

#endif /*FOURTHANDFIVE_VIEW_H */

