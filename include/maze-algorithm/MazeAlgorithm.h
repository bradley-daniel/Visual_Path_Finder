//
// Created by Bradley Daniel on 3/14/23.
//

#ifndef VISUAL_PATH_FINDER_MAZEALGORITHM_H
#define VISUAL_PATH_FINDER_MAZEALGORITHM_H

namespace grid { class Grid; }

namespace algorithm {
    class MazeAlgorithm {
    protected:
        grid::Grid* m_grid;
    public:
        explicit MazeAlgorithm(grid::Grid *grid);
    };
}


#endif //VISUAL_PATH_FINDER_MAZEALGORITHM_H
