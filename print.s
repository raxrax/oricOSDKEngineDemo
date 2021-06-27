; ----------------------------------------------------------------------
_elementSrc   .word   0
_elementDst   .word   0
_elementWidth .byte   4
_elementHight .byte   24
; ----------------------------------------------------------------------
_printElementA
              
              lda   _elementSrc
              sta   xorsprite+1
              lda   _elementSrc+1
              sta   xorsprite+2

              lda   _elementDst
              sta   xorbg+1
              sta   adst+1
              lda   _elementDst+1
              sta   xorbg+2
              sta   adst+2

              ldx   #0
loop          ldy   #0

loopy
xorbg         lda   $1234,y
xorsprite     eor   $1234,y
              ora   #64

adst          sta   $f00d,y

              iny
              cpy   _elementWidth
              bne   loopy

              clc
              lda   #<40
              adc   adst+1
              sta   adst+1
              bcc   skip1
              inc   adst+2
              clc
skip1
skip2
              lda   #<40
              adc   xorbg+1
              sta   xorbg+1
              bcc   skip3
              inc   xorbg+2
              clc
skip3
              lda   #<40
              adc   xorsprite+1
              sta   xorsprite+1
              bcc   skip4
              inc   xorsprite+2
skip4
              inx
              cpx   _elementHight
              bne   loop

              rts   

