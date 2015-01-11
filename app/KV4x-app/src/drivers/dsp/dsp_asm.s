	SECTION .noinit : CODE

	EXPORT	__mla

	EXPORT	__smlal
	EXPORT	__smull

	EXPORT	__smlabb
	EXPORT	__smlabt
	EXPORT	__smlatb
	EXPORT	__smlatt

	EXPORT	__smlad
	EXPORT	__smladx

	EXPORT	__smlalbb
	EXPORT	__smlalbt
	EXPORT	__smlaltb
	EXPORT	__smlaltt

	EXPORT	__smlald
	EXPORT	__smlaldx

	EXPORT	__smlawb
	EXPORT	__smlawt

	EXPORT	__smlsd
	EXPORT	__smlsdx

	EXPORT	__smlsld
	EXPORT	__smlsldx

	EXPORT	__smmla
	EXPORT	__smmlar

	EXPORT	__smmls
	EXPORT	__smmlsr

	EXPORT	__smmul
	EXPORT	__smmulr

	EXPORT	__smuad
	EXPORT	__smuadx

	EXPORT	__smulbb
	EXPORT	__smulbt
	EXPORT	__smultb
	EXPORT	__smultt

	EXPORT	__smulwb
	EXPORT	__smulwt

	EXPORT	__smusd
	EXPORT	__smusdx

	EXPORT	__umlal
	EXPORT	__umull

	EXPORT	__umaal

__mla:
	mla	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate Long
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlal:
	smlal	r0, r1, r2, r3
	bx	lr

; Signed Multiply Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__smull:
	smull	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate, halfwords
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlabb:
	smlabb	r0, r1, r2, r3
	bx	lr

__smlabt:
	smlabt	r0, r1, r2, r3
	bx	lr

__smlatb:
	smlatb	r0, r1, r2, r3
	bx	lr

__smlatt:
	smlatt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate Dual
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlad:
	smlad	r0, r1, r2, r3
	bx	lr

__smladx:
	smladx	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate long, halfwords
; r0 - lower 32 bits of accumulate value
; r1 - upper 32 bits of accumulate value
; r2 - x
; r3 - y
__smlalbb:
	smlalbb	r0, r1, r2, r3
	bx	lr

__smlalbt:
	smlalbt	r0, r1, r2, r3
	bx	lr

__smlaltb:
	smlaltb	r0, r1, r2, r3
	bx	lr

__smlaltt:
	smlaltt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate Long Dual
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlald:
	smlald	r0, r1, r2, r3
	bx	lr

__smlaldx:
	smlaldx	r0, r1, r2, r3
	bx	lr

; signed Multipl Accumulate, word by halfword
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlawb:
	smlawb	r0, r1, r2, r3
	bx	lr

__smlawt:
	smlawt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Subtract Dual
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlsd:
	smlsd	r0, r1, r2, r3
	bx	lr

__smlsdx:
	smlsdx	r0, r1, r2, r3
	bx	lr

; Signed Multiply Subtract Long Dual
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlsld:
	smlsld	r0, r1, r2, r3
	bx	lr

__smlsldx:
	smlsldx	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply Accumulate
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smmla:
	smmla	r0, r1, r2, r3
	bx	lr

__smmlar:
	smmlar	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply Subtract
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smmls:
	smmls	r0, r1, r2, r3
	bx	lr

__smmlsr:
	smmlsr	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply
; r0 - 32 bits Accumulate and return result
; r1 - x
; r2 - y
__smmul:
	smmul	r0, r1, r2
	bx	lr

__smmulr:
	smmulr	r0, r1, r2
	bx	lr

; Signed Dual Multiply Add
; r0 - Return result
; r1 - x
; r2 - y
__smuad:
	smuad	r0, r1, r2
	bx	lr

__smuadx:
	smuadx	r0, r1, r2
	bx	lr

; Signed Multiply, halfwords
; r0 - return result
; r1 - x
; r2 - y
__smulbb:
	smulbb	r0, r1, r2
	bx	lr

__smulbt:
	smulbt	r0, r1, r2
	bx	lr

__smultb:
	smultb	r0, r1, r2
	bx	lr

__smultt:
	smultt	r0, r1, r2
	bx	lr

; Signed Multiply, word by halfwords
; r0 - return result
; r1 - x
; r2 - y
__smulwb:
	smulwb	r0, r1, r2
	bx	lr

__smulwt:
	smulwt	r0, r1, r2
	bx	lr

; Signed Dual Multiply Subtract
; r0 - return result
; r1 - x
; r2 - y
__smusd:
	smusd	r0, r1, r2
	bx	lr

__smusdx:
	smusdx	r0, r1, r2
	bx	lr

; Unsigned Multiply Accumulate Long
; r0 - lower 32 bits Accumulate and return result
; r1 - upper 32 bits Accumulate and return result
; r2 - x
; r3 - y
__umlal:
	umlal	r0, r1, r2, r3
	bx	lr

; Unsigned Multiply Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__umull:
	umull	r0, r1, r2, r3
	bx	lr

; Unsigned Multiply Accumulate Accumulate Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__umaal:
	umaal	r0, r1, r2, r3
	bx	lr

        END
