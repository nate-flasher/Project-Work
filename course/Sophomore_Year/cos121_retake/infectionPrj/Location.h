/**
 * Declaration of the Actor class.
 *
 * @author Jonathan Geisler
 * @date November 2019
 */
#ifndef LOCATION_H
#define LOCATION_H

class Location {
  public:
    int row;
    int col;

    bool operator==(const Location& other) const;
};

#endif
