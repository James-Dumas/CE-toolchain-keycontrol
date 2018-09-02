# CE-toolchain-keycontrol
For use with [the CE C Toolchain](https://github.com/CE-Programming/toolchain)

Provides three functions to allow simpler detection of keypresses. The function `kc_update()` must be called regularly during execution in order for them to function properly.

- `bool kc_state(char* key)` - returns current pressed state of key
- `bool kc_pressed(char* key)` - returns whether key was pressed since last call to `kc_update()`
- `bool kc_released(char* key)` - returns whether key was unpressed since last call to `kc_update()`

# Keys
Each key has an associated string used with the three aforementioned functions.

| yequals | window | zoom | trace | graph |
|:-:|:-:|:-:|:-:|:-:|
| 2nd | mode | del | up | right |
| alpha | x | stat | left | down |
| math | apps | prgm | vars | clear |
| recip | sin | cos | tan | power |
| square | comma | lparen | rparen | div |
| log | 7 | 8 | 9 | mult |
| ln | 4 | 5 | 6 | sub |
| sto | 1 | 2 | 3 | add |
| | 0 | dec | neg | enter |
