/**
 * Copyright (c) 2011-2015 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

const double RColor::cadColors[][3] = {
        {0,0,0},                // ByBlock (unused in this array)
        {1,0,0},                // 1
        {1,1,0},
        {0,1,0},
        {0,1,1},
        {0,0,1},
        {1,0,1},
        {1,1,1},                // black or white
        {0.5,0.5,0.5},
        {0.75,0.75,0.75},
        {1,0,0},                // 10
        {1,0.5,0.5},
        {0.65,0,0},
        {0.65,0.325,0.325},
        {0.5,0,0},
        {0.5,0.25,0.25},
        {0.3,0,0},
        {0.3,0.15,0.15},
        {0.15,0,0},
        {0.15,0.075,0.075},
        {1,0.25,0},             // 20
        {1,0.625,0.5},
        {0.65,0.1625,0},
        {0.65,0.4063,0.325},
        {0.5,0.125,0},
        {0.5,0.3125,0.25},
        {0.3,0.075,0},
        {0.3,0.1875,0.15},
        {0.15,0.0375,0},
        {0.15,0.0938,0.075},
        {1,0.5,0},              // 30
        {1,0.75,0.5},
        {0.65,0.325,0},
        {0.65,0.4875,0.325},
        {0.5,0.25,0},
        {0.5,0.375,0.25},
        {0.3,0.15,0},
        {0.3,0.225,0.15},
        {0.15,0.075,0},
        {0.15,0.1125,0.075},
        {1,0.75,0},             // 40
        {1,0.875,0.5},
        {0.65,0.4875,0},
        {0.65,0.5688,0.325},
        {0.5,0.375,0},
        {0.5,0.4375,0.25},
        {0.3,0.225,0},
        {0.3,0.2625,0.15},
        {0.15,0.1125,0},
        {0.15,0.1313,0.075},
        {1,1,0},                // 50
        {1,1,0.5},
        {0.65,0.65,0},
        {0.65,0.65,0.325},
        {0.5,0.5,0},
        {0.5,0.5,0.25},
        {0.3,0.3,0},
        {0.3,0.3,0.15},
        {0.15,0.15,0},
        {0.15,0.15,0.075},
        {0.75,1,0},             // 60
        {0.875,1,0.5},
        {0.4875,0.65,0},
        {0.5688,0.65,0.325},
        {0.375,0.5,0},
        {0.4375,0.5,0.25},
        {0.225,0.3,0},
        {0.2625,0.3,0.15},
        {0.1125,0.15,0},
        {0.1313,0.15,0.075},
        {0.5,1,0},              // 70
        {0.75,1,0.5},
        {0.325,0.65,0},
        {0.4875,0.65,0.325},
        {0.25,0.5,0},
        {0.375,0.5,0.25},
        {0.15,0.3,0},
        {0.225,0.3,0.15},
        {0.075,0.15,0},
        {0.1125,0.15,0.075},
        {0.25,1,0},             // 80
        {0.625,1,0.5},
        {0.1625,0.65,0},
        {0.4063,0.65,0.325},
        {0.125,0.5,0},
        {0.3125,0.5,0.25},
        {0.075,0.3,0},
        {0.1875,0.3,0.15},
        {0.0375,0.15,0},
        {0.0938,0.15,0.075},
        {0,1,0},                // 90
        {0.5,1,0.5},
        {0,0.65,0},
        {0.325,0.65,0.325},
        {0,0.5,0},
        {0.25,0.5,0.25},
        {0,0.3,0},
        {0.15,0.3,0.15},
        {0,0.15,0},
        {0.075,0.15,0.075},
        {0,1,0.25},             // 100
        {0.5,1,0.625},
        {0,0.65,0.1625},
        {0.325,0.65,0.4063},
        {0,0.5,0.125},
        {0.25,0.5,0.3125},
        {0,0.3,0.075},
        {0.15,0.3,0.1875},
        {0,0.15,0.0375},
        {0.075,0.15,0.0938},
        {0,1,0.5},              // 110
        {0.5,1,0.75},
        {0,0.65,0.325},
        {0.325,0.65,0.4875},
        {0,0.5,0.25},
        {0.25,0.5,0.375},
        {0,0.3,0.15},
        {0.15,0.3,0.225},
        {0,0.15,0.075},
        {0.075,0.15,0.1125},
        {0,1,0.75},             // 120
        {0.5,1,0.875},
        {0,0.65,0.4875},
        {0.325,0.65,0.5688},
        {0,0.5,0.375},
        {0.25,0.5,0.4375},
        {0,0.3,0.225},
        {0.15,0.3,0.2625},
        {0,0.15,0.1125},
        {0.075,0.15,0.1313},
        {0,1,1},                // 130
        {0.5,1,1},
        {0,0.65,0.65},
        {0.325,0.65,0.65},
        {0,0.5,0.5},
        {0.25,0.5,0.5},
        {0,0.3,0.3},
        {0.15,0.3,0.3},
        {0,0.15,0.15},
        {0.075,0.15,0.15},
        {0,0.75,1},             // 140
        {0.5,0.875,1},
        {0,0.4875,0.65},
        {0.325,0.5688,0.65},
        {0,0.375,0.5},
        {0.25,0.4375,0.5},
        {0,0.225,0.3},
        {0.15,0.2625,0.3},
        {0,0.1125,0.15},
        {0.075,0.1313,0.15},
        {0,0.5,1},              // 150
        {0.5,0.75,1},
        {0,0.325,0.65},
        {0.325,0.4875,0.65},
        {0,0.25,0.5},
        {0.25,0.375,0.5},
        {0,0.15,0.3},
        {0.15,0.225,0.3},
        {0,0.075,0.15},
        {0.075,0.1125,0.15},
        {0,0.25,1},             // 160
        {0.5,0.625,1},
        {0,0.1625,0.65},
        {0.325,0.4063,0.65},
        {0,0.125,0.5},
        {0.25,0.3125,0.5},
        {0,0.075,0.3},
        {0.15,0.1875,0.3},
        {0,0.0375,0.15},
        {0.075,0.0938,0.15},
        {0,0,1},                // 170
        {0.5,0.5,1},
        {0,0,0.65},
        {0.325,0.325,0.65},
        {0,0,0.5},
        {0.25,0.25,0.5},
        {0,0,0.3},
        {0.15,0.15,0.3},
        {0,0,0.15},
        {0.075,0.075,0.15},
        {0.25,0,1},             // 180
        {0.625,0.5,1},
        {0.1625,0,0.65},
        {0.4063,0.325,0.65},
        {0.125,0,0.5},
        {0.3125,0.25,0.5},
        {0.075,0,0.3},
        {0.1875,0.15,0.3},
        {0.0375,0,0.15},
        {0.0938,0.075,0.15},
        {0.5,0,1},              // 190
        {0.75,0.5,1},
        {0.325,0,0.65},
        {0.4875,0.325,0.65},
        {0.25,0,0.5},
        {0.375,0.25,0.5},
        {0.15,0,0.3},
        {0.225,0.15,0.3},
        {0.075,0,0.15},
        {0.1125,0.075,0.15},
        {0.75,0,1},             // 200
        {0.875,0.5,1},
        {0.4875,0,0.65},
        {0.5688,0.325,0.65},
        {0.375,0,0.5},
        {0.4375,0.25,0.5},
        {0.225,0,0.3},
        {0.2625,0.15,0.3},
        {0.1125,0,0.15},
        {0.1313,0.075,0.15},
        {1,0,1},                // 210
        {1,0.5,1},
        {0.65,0,0.65},
        {0.65,0.325,0.65},
        {0.5,0,0.5},
        {0.5,0.25,0.5},
        {0.3,0,0.3},
        {0.3,0.15,0.3},
        {0.15,0,0.15},
        {0.15,0.075,0.15},
        {1,0,0.75},             // 220
        {1,0.5,0.875},
        {0.65,0,0.4875},
        {0.65,0.325,0.5688},
        {0.5,0,0.375},
        {0.5,0.25,0.4375},
        {0.3,0,0.225},
        {0.3,0.15,0.2625},
        {0.15,0,0.1125},
        {0.15,0.075,0.1313},
        {1,0,0.5},              // 230
        {1,0.5,0.75},
        {0.65,0,0.325},
        {0.65,0.325,0.4875},
        {0.5,0,0.25},
        {0.5,0.25,0.375},
        {0.3,0,0.15},
        {0.3,0.15,0.225},
        {0.15,0,0.075},
        {0.15,0.075,0.1125},
        {1,0,0.25},             // 240
        {1,0.5,0.625},
        {0.65,0,0.1625},
        {0.65,0.325,0.4063},
        {0.5,0,0.125},
        {0.5,0.25,0.3125},
        {0.3,0,0.075},
        {0.3,0.15,0.1875},
        {0.15,0,0.0375},
        {0.15,0.075,0.0938},
        {0.33,0.33,0.33},       // 250
        {0.464,0.464,0.464},
        {0.598,0.598,0.598},
        {0.732,0.732,0.732},
        {0.866,0.866,0.866},
        {1,1,1}                 // 255
    };
