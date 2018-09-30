# lem_in
program receive the data describing the ant farm from the standard output
in the following format:

	number_of_ants

	the_rooms

	the_links

The ant farm is defined by the following links:

##start <br />
1 23 3 <br />
2 16 7 <br />
#comment <br />
3 16 3 <br />
4 16 5 <br />
5 9 3 <br />
6 1 5 <br />
7 4 8 <br />
##end <br />
0 9 5 <br />
0-4 <br />
0-6 <br />
1-3 <br />
4-3 <br />
5-2 <br />
3-5 <br />
#another comment <br />
4-2 <br />
2-1 <br />
7-6 <br />
7-2 <br />
7-4 <br />
6-5 <br />

There are two parts:

	The rooms, which are defined by: name coord_x coord_y

	The links, which are defined by: name1-name2

	All of it is broken by comments, which start with #

Lines that start with ## are commands modifying the properties of the line that
comes right after.

For example, ##start signals the ant farm’s entrance and ##end its exit.

Any non compliant or empty lines will automatically stop the ant farm’s reading
as well as the orderly processing of the acquired data.

If there isn’t enough data to process normally you must display ERROR.
