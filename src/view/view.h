#ifndef FOURTHANDFIVE_VIEW_H
#define FOURTHANDFIVE_VIEW_H

#include <cstddef>

namespace fourthandfive {

inline constexpr std::size_t k_FIELD_VIEW_ROW_SIZE = 121uz;
inline constexpr std::size_t k_FIELD_VIEW_ROWS = 7uz;
inline constexpr std::size_t k_FIELD_VIEW_SIZE = k_FIELD_VIEW_ROW_SIZE * k_FIELD_VIEW_ROWS;
inline constexpr std::size_t k_FIELD_VIEW_MIN_ROWS = k_FIELD_VIEW_ROWS;
inline constexpr std::size_t k_FIELD_VIEW_MIN_COLUMNS = k_FIELD_VIEW_ROW_SIZE;

inline constexpr std::size_t k_INPUT_VIEW_ROW_SIZE = 5uz;
inline constexpr std::size_t k_INPUT_VIEW_ROWS = 1uz;
inline constexpr std::size_t k_INPUT_VIEW_SIZE = k_INPUT_VIEW_ROW_SIZE * k_INPUT_VIEW_ROWS;
inline constexpr std::size_t k_INPUT_VIEW_MIN_ROWS = k_INPUT_VIEW_ROWS;
inline constexpr std::size_t k_INPUT_VIEW_MIN_COLUMNS = k_INPUT_VIEW_ROW_SIZE;

} // close namespace fourthandfive

#endif /*FOURTHANDFIVE_VIEW_H */

