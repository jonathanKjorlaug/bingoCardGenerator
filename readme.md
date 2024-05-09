## Bingo card generator!

This is a bingo card generator that uses c++ in order to write a randomly ordered bingo card to a tex-file, which can then be compiled and printed.

### Dependencies

One must have c++ set up locally, using the meson build system. I have personally used [this] (https://tdt4102.pages.stud.idi.ntnu.no/documentation/installing/linux/) guide.

### Basic usage

Once one has c++ installed and set up, one must first clone the repo, and enter it. You should add your bingo card entries to ´input.txt´, separated by newlines with no blank lines between them. After one has done this, run:

'''
meson compile -C builddir && ./builddir/program
'''

After this is done, you should see a newly generated tex-file at ´bingoCard.tex´. Do with it as you wish.


### Configuration

If you do not like the standard values for the file paths, or the maximum size of the bingo card, you can change these constants in ´bingoCardGenerator.h´.
