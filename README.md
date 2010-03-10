algorithms
======
A repository for is207; a course on Algorithms and Data Structures
at the University of Agder.

* Simple sorting.
* Simple searching.
* A few basic data structures.
* More advanced sorting like merge, quicksort and shellsort.
* More advanced data structures like tree's.

Getting Started
---------------

*   `$ git clone git://github.com/simonz05/algorithms.git`
*   Use `$ make` to test different algorithms.
*   Storage; queue, linked-list etc. depend on [Go](http://golang.org)
*   Sort & Search; Sorting algorithms currently have only C (gcc) deps.
    Searching test file is using [citrus](http://github.com/simonz05/citrus). Both
    sorting and searching makefile depend on having citrus installed as
    shared lib.
    It's of course possible to build these algorithms without the citrus
    dependency.
*   I've added a range of [BlueJ](http://www.bluej.org/) packages.
    I've kept the meta-data when commiting to github. It's possible these
    meta files seem confusing, but if you'd like to the test the algorithms
    I recommend getting BlueJ. It's a nice tool for learning about algorithms
    in Java due to it's simple debugger.


License
-------
algorithms
Copyright (C) 2010  Simon Zimmermann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
