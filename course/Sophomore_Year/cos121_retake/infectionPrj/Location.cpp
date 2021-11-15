/**
 * @file Location.cpp
 * @brief The Location class implementation file.
 * @author Jonathan Geisler
 * @date November 2019
 */
#include "Location.h"

bool Location::operator==(const Location& other) const {
    return row == other.row && col == other.col;
}
