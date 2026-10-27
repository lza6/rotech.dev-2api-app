.global setjmp
.type setjmp,@function
setjmp:
  b __sigsetjmp
.global longjmp
.type longjmp,@function
longjmp:
  b longjmp
