/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macrosft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 04:43:07 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 22:18:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROSFT_H
# define MACROSFT_H

# define N(_1, _2, _3, _4, _5, _6, _7, _8, F, ...) F

/*
# define N1(_1, _2, _3, _4, _5, _6, _7, _8, ...) N2(__VA_ARGS__)
# define N2(_9, _10, _11, _12, _13, _14, _15, _16, ...) N3(__VA_ARGS__)
# define N3(_17, _18, _19, _20, _21, _22, _23, _24, ...) N4(__VA_ARGS__)
# define N4(_25, _26, _27, _28, _29, _30, _31, _32, ...) N5(__VA_ARGS__)
# define N5(_33, _34, _35, _36, _37, _38, _39, _40, ...) N6(__VA_ARGS__)
# define N6(_41, _42, _43, _44, _45, _46, _47, _48, ...) N7(__VA_ARGS__)
# define N7(_49, _50, _51, _52, _53, _54, _55, _56, ...) N8(__VA_ARGS__)
# define N8(_57, _58, _59, _60, _61, _62, _63, NUM, ...) NUM

# define REVN() REVN1()
# define REVN1() 63, 62, 61, 60, 59, 58, 57, REVN2()
# define REVN2() 56, 55, 54, 53, 52, 51, 50, 49, REVN3()
# define REVN3() 48, 47, 46, 45, 44, 43, 42, 41, REVN4()
# define REVN4() 40, 39, 38, 37, 36, 35, 34, 33, REVN5()
# define REVN5() 32, 31, 30, 29, 28, 27, 26, 25, REVN6()
# define REVN6() 24, 23, 22, 21, 20, 19, 18, 17, REVN7()
# define REVN7() 16, 15, 14, 13, 12, 11, 10, 9, REVN8()
# define REVN8() 8, 7, 6, 5, 4, 3, 2, 1, 0
*/

# define NOT(x) (!(x))

# define OR(...) N(__VA_ARGS__,OR8,OR7,OR6,OR5,OR4,OR3,OR2,OR1)(__VA_ARGS__)
# define OR1(a) (a)
# define OR2(a,b) (a||b)
# define OR3(a,b,c) (a||b||c)
# define OR4(a,b,c,d) (a||b||c||d)
# define OR5(a,b,c,d,e) (a||b||c||d||e)
# define OR6(a,b,c,d,e,f) (a||b||c||d||e||f)
# define OR7(a,b,c,d,e,f,g) (a||b||c||d||e||f||g)
# define OR8(a,b,c,d,e,f,g,h) (a||b||c||d||e||f||g||h)

# define AND(...) N(__VA_ARGS__,ND8,ND7,ND6,ND5,ND4,ND3,ND2,ND1)(__VA_ARGS__)
# define ND1(a) (a)
# define ND2(a,b) (a&&b)
# define ND3(a,b,c) (a&&b&&c)
# define ND4(a,b,c,d) (a&&b&&c&&d)
# define ND5(a,b,c,d,e) (a&&b&&c&&d&&e)
# define ND6(a,b,c,d,e,f) (a&&b&&c&&d&&e&&f)
# define ND7(a,b,c,d,e,f,g) (a&&b&&c&&d&&e&&f&&g)
# define ND8(a,b,c,d,e,f,g,h) (a&&b&&c&&d&&e&&f&&g&&h)

# define OP(op, ...) N(__VA_ARGS__,O8,O7,O6,O5,O4,O3,O2,O1)(op, __VA_ARGS__)
# define O1(op,a) op(a)
# define O2(op,a,b) O1(op,a), op(b)
# define O3(op,a,b,c) O2(op,a,b), op(c)
# define O4(op,a,b,c,d) O3(op,a,b,c), op(d)
# define O5(op,a,b,c,d,e) O4(op,a,b,c,d), op(e)
# define O6(op,a,b,c,d,e,f) O5(op,a,b,c,d,e), op(f)
# define O7(op,a,b,c,d,e,f,g) O6(op,a,b,c,d,e,f), op(g)
# define O8(op,a,b,c,d,e,f,g,h) O7(op,a,b,c,d,e,f,g), op(h)

# define DO(...) N(__VA_ARGS__,DO8,DO7,DO6,DO5,DO4,DO3,DO2,DO1)(__VA_ARGS__)
# define DO1(a) a;
# define DO2(a,b) DO1(a) b;
# define DO3(a,b,c) DO2(a,b) c;
# define DO4(a,b,c,d) DO3(a,b,c) d;
# define DO5(a,b,c,d,e) DO4(a,b,c,d) e;
# define DO6(a,b,c,d,e,f) DO5(a,b,c,d,e) f;
# define DO7(a,b,c,d,e,f,g) DO6(a,b,c,d,e,f) g;
# define DO8(a,b,c,d,e,f,g,h) DO7(a,b,c,d,e,f,g) h;

# define RET(ret) return (ret);
# define IF(cond, ...) if (cond) { DO(__VA_ARGS__) }
# define RETIF(ret, cond) if (cond) return (ret);
# define NULLIF(cond) RETIF(NULL, cond);
# define NULLCHECK(...) RETIF(NULL, (NOT(AND(__VA_ARGS__))));
# define RNULLCHECK(ret, ...) RETIF(ret, (NOT(AND(__VA_ARGS__))));
# define FREE(...) OP(free, __VA_ARGS__)
# define CHKALLOC(...) IF(NOT(AND(__VA_ARGS__)),FREE(__VA_ARGS__),return(NULL))

# define MIN(...) N(__VA_ARGS__,MN8,MN7,MN6,MN5,MN4,MN3,MN2,MN1)(__VA_ARGS__)
# define MN1(a) (a)
# define MN2(a,b) (a<b?a:b)
# define MN3(a,b,c) (MN2(a,b)<c?MN2(a,b):c)
# define MN4(a,b,c,d) (MN3(a,b,c)<d?MN3(a,b,c):d)
# define MN5(a,b,c,d,e) (MN4(a,b,c,d)<e?MN4(a,b,c,d):e)
# define MN6(a,b,c,d,e,f) (MN5(a,b,c,d,e)<f?MN5(a,b,c,d,e):f)
# define MN7(a,b,c,d,e,f,g) (MN6(a,b,c,d,e,f)<g?MN6(a,b,c,d,e,f):g)
# define MN8(a,b,c,d,e,f,g,h) (MN7(a,b,c,d,e,f,g)<h?MN7(a,b,c,d,e,f,g):h)

# define MAX(...) N(__VA_ARGS__,MX8,MX7,MX6,MX5,MX4,MX3,MX2,MX1)(__VA_ARGS__)
# define MX1(a) (a)
# define MX2(a,b) (a>b?a:b)
# define MX3(a,b,c) (MX2(a,b)>c?MX2(a,b):c)
# define MX4(a,b,c,d) (MX3(a,b,c)>d?MX3(a,b,c):d)
# define MX5(a,b,c,d,e) (MX4(a,b,c,d)>e?MX4(a,b,c,d):e)
# define MX6(a,b,c,d,e,f) (MX5(a,b,c,d,e)>f?MX5(a,b,c,d,e):f)
# define MX7(a,b,c,d,e,f,g) (MX6(a,b,c,d,e,f)>g?MX6(a,b,c,d,e,f):g)
# define MX8(a,b,c,d,e,f,g,h) (MX7(a,b,c,d,e,f,g)>h?MX7(a,b,c,d,e,f,g):h)

# define POW(n, e) POW##e(n)
# define POW1(n) (n)
# define POW2(n) (n*n)
# define POW3(n) (n*n*n)
# define POW4(n) (n*n*n*n)
# define POW5(n) (n*n*n*n*n)
# define POW6(n) (n*n*n*n*n*n)
# define POW7(n) (n*n*n*n*n*n*n)
# define POW8(n) (n*n*n*n*n*n*n*n)
# define POW9(n) (POW(8)*POW(1))
# define POW10(n) (POW(8)*POW(2))
# define POW11(n) (POW(8)*POW(3))
# define POW12(n) (POW(8)*POW(4))
# define POW13(n) (POW(8)*POW(5))
# define POW14(n) (POW(8)*POW(6))
# define POW15(n) (POW(8)*POW(7))
# define POW16(n) (POW(8)*POW(8))
# define POW17(n) (POW(16)*POW(1))
# define POW18(n) (POW(16)*POW(2))
# define POW19(n) (POW(16)*POW(3))
# define POW20(n) (POW(16)*POW(4))
# define POW21(n) (POW(16)*POW(5))
# define POW22(n) (POW(16)*POW(6))
# define POW23(n) (POW(16)*POW(7))
# define POW24(n) (POW(16)*POW(8))
# define POW25(n) (POW(24)*POW(1))
# define POW26(n) (POW(24)*POW(2))
# define POW27(n) (POW(24)*POW(3))
# define POW28(n) (POW(24)*POW(4))
# define POW29(n) (POW(24)*POW(5))
# define POW30(n) (POW(24)*POW(6))
# define POW31(n) (POW(24)*POW(7))
# define POW32(n) (POW(24)*POW(8))
# define POW33(n) (POW(32)*POW(1))
# define POW34(n) (POW(32)*POW(2))
# define POW35(n) (POW(32)*POW(3))
# define POW36(n) (POW(32)*POW(4))
# define POW37(n) (POW(32)*POW(5))
# define POW38(n) (POW(32)*POW(6))
# define POW39(n) (POW(32)*POW(7))
# define POW40(n) (POW(32)*POW(8))
# define POW41(n) (POW(40)*POW(1))
# define POW42(n) (POW(40)*POW(2))
# define POW43(n) (POW(40)*POW(3))
# define POW44(n) (POW(40)*POW(4))
# define POW45(n) (POW(40)*POW(5))
# define POW46(n) (POW(40)*POW(6))
# define POW47(n) (POW(40)*POW(7))
# define POW48(n) (POW(40)*POW(8))
# define POW49(n) (POW(48)*POW(1))
# define POW50(n) (POW(48)*POW(2))
# define POW51(n) (POW(48)*POW(3))
# define POW52(n) (POW(48)*POW(4))
# define POW53(n) (POW(48)*POW(5))
# define POW54(n) (POW(48)*POW(6))
# define POW55(n) (POW(48)*POW(7))
# define POW56(n) (POW(48)*POW(8))
# define POW57(n) (POW(56)*POW(1))
# define POW58(n) (POW(56)*POW(2))
# define POW59(n) (POW(56)*POW(3))
# define POW60(n) (POW(56)*POW(4))
# define POW61(n) (POW(56)*POW(5))
# define POW62(n) (POW(56)*POW(6))
# define POW63(n) (POW(56)*POW(7))

# define FAC(n) FAC##n
# define FAC0 1
# define FAC1 1
# define FAC2 2
# define FAC3 6
# define FAC4 24
# define FAC5 120
# define FAC6 720
# define FAC7 5040
# define FAC8 40320
# define FAC9 362880
# define FAC10 3628800
# define FAC11 39916800
# define FAC12 479001600
# define FAC13 6227020800
# define FAC14 87178291200
# define FAC15 137674368000
# define FAC16 20922789888000
# define FAC17 355687428096000
# define FAC18 6402373705728000

# define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n' ISSPACE2(c)
# define ISSPACE2(c) || c == '\r' || c == '\v' || c == '\f')
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef enum
{
	false,
	true
}	t_bool;

#endif
