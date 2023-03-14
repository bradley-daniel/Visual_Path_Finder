//
// Created by Bradley Daniel on 3/13/23.
//

#ifndef VISUAL_PATH_FINDER_COORD_H
#define VISUAL_PATH_FINDER_COORD_H

namespace grid {
    struct Coord {
    public:
        int m_x, m_y;
        Coord(int x, int y);
    public:
        [[nodiscard]] int flatten_Coord(int width) const;

        Coord();
    };
}


#endif //VISUAL_PATH_FINDER_COORD_H
