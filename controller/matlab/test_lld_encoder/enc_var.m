% -------------------------------------------------------------------
%  Generated by MATLAB on 3-Apr-2021 16:21:59
%  MATLAB version: 9.1.0.441655 (R2016b)
% -------------------------------------------------------------------
saveVarsMat = load('enc_var.mat');

A = saveVarsMat.A; % <3000x1 double> too many elements

B = [174 365 60 249 444 147 344 49 250 451 156 353 57 257 455 157 346 38 ...
     232 428 133 331 33 234 436 142 341 45 248 453 163 362 72 279 485 193 ...
     394 101 297 488 182 372 71 270 472 182 387 100 303 10 220 428 138 ...
     336 43 252 462 175 379 88 290 490 188 380 79 276 477 184 387 98 300 ...
     10 223 436 151 355 70 282 496 207 414 125 327 31 228 423 125 322 27 ...
     235 445 163 371 83 289 497 207 418 134 339 51 264 479 196 405 114 ...
     311 5 198 393 100 305 17 232 443 155 361 80 291 2 217 431 145 349 ...
     62 276 491 204 408 115 311 11 215 418 131 339 53 264 472 188 398 111 ...
     319 34 246 457 175 384 101 309 10 212 413 120 320 27 237 448 166 376 ...
     91 302 14 226 439 159 366 82 296 10 226 438 145 341 44 248 452 164 ...
     370 88 300 15 229 442 158 368 89 302 16 231 449 168 376 89 289 486 ...
     192 398 111 317 28 243 455 169 376 94 306 23 245 460 174 386 108 322 ...
     37 249 453 162 364 77 283 493 206 418 137 346 63 274 488 206 423 139 ...
     346 65 284 498 215 425 138 343 55 265 474 187 394 109 317 30 246 462 ...
     185 401 123 337 57 276 494 210 420 132 337 45 255 464 178 383 95 300 ...
     10 222 433 147 356 77 291 7 226 443 160 372 92 303 15 229 439 149 ...
     349 53 256 459 170 376 92 305 23 242 455 174 389 108 322 43 262 473 ...
     188 399 114 320 26 231 435 145 350 63 274 486 202 414 133 347 70 288 ...
     6 228 440 154 362 78 288 499 209 410 118 321 34 249 463 185 401 124 ...
     335 52 268 479 194 405 121 326 40 258 473 190 393 96 292 493 201 409 ...
     128 339 54 261 470 187 402 120 332 48 262 475 190 400 116 321 27 227 ...
     426 131 332 40 250 460 178 391 107 316 32 246 462 180 390 111 326 ...
     42 255 462 169 368 73 276 485 200 415 139 354 73 284 498 216 435 159 ...
     376 94 309 30 249 464 177 378 86 290 1 215 429 151 366 87 299 16 230 ...
     443 162 375 96 312 34 247 459 173 371 77 280 485 194 402 121 334 53 ...
     268 482 202 418 141 353 70 283 0 223 439 159 367 74 275 478 186 391 ...
     105 313 25 228 429 139 346 59 272 487 208 424 146 363 87 302 14 218 ...
     420 129 332 40 250 459 177 389 106 318 32 239 449 168 378 98 314 34 ...
     247 457 168 368 75 280 486 196 403 120 331 47 261 475 191 402 123 ...
     336 54 274 495 216 431 149 355 67 275 485 197 406 123 331 46 261 474 ...
     191 404 122 334 52 270 492 216 438 158 364 76 285 496 212 424 139 ...
     344 27 181 314 456 93 203 316 408 478 46 111 137 147 147 147 147 147 ...
     147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 ...
     147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 ...
     147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 147 ...
     147 147 147 147 147 147 147 147 147 147 147 147 147 147 144 113 64 ...
     31 -16 -89 -172 -264 -349 -456 -60 -180 -308 -435 -56 -191 -333 -476 ...
     -119 -265 -407 -54 -204 -355 -9 -162 -320 -479 -141 -304 -473 -145 ...
     -322 -494 -169 -348 -30 -216 -399 -80 -264 -450 -135 -324 -14 -202 ...
     -390 -74 -259 -445 -128 -310 -486 -160 -344 -33 -221 -414 -109 -299 ...
     -482 -169 -364 -64 -264 -466 -163 -355 -47 -238 -431 -119 -307 -495 ...
     -183 -375 -58 -239 -423 -111 -304 -499 -192 -384 -72 -265 -461 -154 ...
     -351 -50 -247 -445 -138 -335 -32 -228 -426 -121 -314 0 -176 -354 -36 ...
     -219 -413 -109 -297 -489 -176 -367 -61 -259 -458 -154 -352 -47 -244 ...
     -434 -124 -316 -8 -197 -391 -86 -273 -452 -127 -312 -2 -191 -382 -75 ...
     -271 -467 -165 -364 -63 -261 -458 -148 -339 -32 -228 -424 -116 -307 ...
     -497 -185 -372 -51 -228 -411 -97 -289 -481 -172 -362 -49 -240 -433 ...
     -125 -322 -23 -221 -420 -119 -321 -17 -208 -403 -91 -278 -459 -134 ...
     -309 -487 -169 -359 -53 -248 -445 -139 -335 -31 -227 -429 -129 -325 ...
     -14 -202 -397 -93 -290 -487 -181 -373 -57 -239 -416 -92 -274 -460 ...
     -147 -337 -28 -220 -414 -105 -298 -493 -189 -388 -84 -281 -475 -167 ...
     -358 -49 -238 -428 -115 -298 -477 -154 -337 -24 -210 -400 -92 -288 ...
     -479 -168 -362 -57 -254 -456 -151 -343 -33 -222 -417 -113 -311 -7 ...
     -197 -380 -60 -241 -426 -112 -305 0 -190 -382 -76 -272 -466 -159 -357 ...
     -54 -250 -442 -132 -326 -20 -213 -411 -106 -300 -487 -167 -350 -35 ...
     -216 -401 -88 -278 -466 -156 -352 -44 -238 -438 -138 -330 -23 -215 ...
     -411 -108 -307 -11 -209 -400 -87 -274 -461 -149 -340 -33 -227 -426 ...
     -126 -324 -19 -214 -415 -118 -321 -25 -226 -428 -123 -319 -18 -215 ...
     -415 -112 -307 -496 -184 -377 -70 -263 -448 -131 -319 -12 -208 -411 ...
     -111 -308 -5 -202 -406 -110 -312 -11 -209 -412 -113 -309 -1 -187 -378 ...
     -72 -268 -464 -156 -348 -42 -235 -435 -133 -332 -29 -228 -431 -130 ...
     -328 -27 -224 -424 -123];

C = [14.347999572753906 14.729999542236328 15.119999885559082 15.498000144958496 ...
     15.88800048828125 16.294000625610352 16.687999725341797 17.097999572753906 ...
     17.5 17.902000427246094 18.312000274658203 18.705999374389648 19.11400032043457 ...
     19.513999938964844 19.909999847412109 20.313999176025391 20.691999435424805 ...
     21.076000213623047 21.464000701904297 21.856000900268555 22.266000747680664 ...
     22.66200065612793 23.065999984741211 23.468000411987305 23.871999740600586 ...
     24.284000396728516 24.681999206542969 25.090000152587891 25.496000289916992 ...
     25.9060001373291 26.326000213623047 26.7239990234375 27.143999099731445 ...
     27.558000564575195 27.969999313354492 28.38599967956543 28.788000106811523 ...
     29.201999664306641 29.5939998626709 29.97599983215332 30.36400032043457 ...
     30.743999481201172 31.142000198364258 31.540000915527344 31.944000244140625 ...
     32.363998413085937 32.773998260498047 33.200000762939453 33.605998992919922 ...
     34.020000457763672 34.439998626708984 34.855998992919922 35.2760009765625 ...
     35.672000885009766 36.08599853515625 36.504001617431641 36.923999786376953 ...
     37.349998474121094 37.757999420166016 38.175998687744141 38.580001831054687 ...
     38.979999542236328 39.375999450683594 39.7599983215332 40.158000946044922 ...
     40.551998138427734 40.953998565673828 41.368000030517578 41.773998260498047 ...
     42.195999145507812 42.599998474121094 43.020000457763672 43.445999145507813 ...
     43.872001647949219 44.301998138427734 44.709999084472656 45.139999389648438 ...
     45.563999176025391 45.992000579833984 46.41400146484375 46.827999114990234 ...
     47.25 47.653999328613281 48.0620002746582 48.456001281738281 48.846000671386719 ...
     49.25 49.644001007080078 50.054000854492187 50.470001220703125 50.889999389648438 ...
     51.326000213623047 51.742000579833984 52.166000366210937 52.577999114990234 ...
     52.993999481201172 53.41400146484375 53.83599853515625 54.268001556396484 ...
     54.678001403808594 55.102001190185547 55.527999877929687 55.958000183105469 ...
     56.391998291015625 56.810001373291016 57.228000640869141 57.622001647949219 ...
     58.0099983215332 58.395999908447266 58.7859992980957 59.200000762939453 ...
     59.610000610351562 60.034000396728516 60.4640007019043 60.886001586914063 ...
     61.310001373291016 61.722000122070312 62.159999847412109 62.582000732421875 ...
     63.004001617431641 63.433998107910156 63.86199951171875 64.290000915527344 ...
     64.697998046875 65.1240005493164 65.552001953125 65.982002258300781 ...
     66.407997131347656 66.816001892089844 67.2300033569336 67.622001647949219 ...
     68.022003173828125 68.430000305175781 68.83599853515625 69.262001037597656 ...
     69.6780014038086 70.106002807617188 70.527999877929688 70.944000244140625 ...
     71.3759994506836 71.7959976196289 72.222000122070313 72.63800048828125 ...
     73.068000793457031 73.491996765136719 73.91400146484375 74.3499984741211 ...
     74.767997741699219 75.2020034790039 75.617996215820312 76.0199966430664 ...
     76.424003601074219 76.825996398925781 77.239997863769531 77.639999389648438 ...
     78.054000854492188 78.4739990234375 78.896003723144531 79.332000732421875 ...
     79.751998901367188 80.181999206542969 80.603996276855469 81.027999877929687 ...
     81.4520034790039 81.877998352050781 82.318000793457031 82.732002258300781 ...
     83.16400146484375 83.592002868652344 84.0199966430664 84.4520034790039 ...
     84.8759994506836 85.290000915527344 85.681999206542969 86.087997436523438 ...
     86.496002197265625 86.903999328613281 87.3280029296875 87.739997863769531 ...
     88.1760025024414 88.5999984741211 89.029998779296875 89.458000183105469 ...
     89.884002685546875 90.316001892089844 90.736000061035156 91.1780014038086 ...
     91.603996276855469 92.031997680664063 92.461997985839844 92.898002624511719 ...
     93.33599853515625 93.751998901367188 94.1780014038086 94.5780029296875 ...
     94.972000122070313 95.384002685546875 95.7959976196289 96.222000122070313 ...
     96.634002685546875 97.055999755859375 97.486000061035156 97.910003662109375 ...
     98.337997436523438 98.751998901367188 99.188003540039063 99.61199951171875 ...
     100.04599761962891 100.48999786376953 100.91999816894531 101.34799957275391 ...
     101.77200317382812 102.21600341796875 102.64399719238281 103.07399749755859 ...
     103.49800109863281 103.90599822998047 104.32399749755859 104.72799682617187 ...
     105.15399932861328 105.56600189208984 105.98600006103516 106.41200256347656 ...
     106.83599853515625 107.27400207519531 107.69200134277344 108.12599945068359 ...
     108.54799652099609 108.97599792480469 109.41200256347656 109.84600067138672 ...
     110.27799987792969 110.69200134277344 111.12999725341797 111.56800079345703 ...
     111.99600219726562 112.43000030517578 112.84999847412109 113.2760009765625 ...
     113.68599700927734 114.11000061035156 114.52999877929687 114.947998046875 ...
     115.37400054931641 115.78800201416016 116.21800231933594 116.63400268554687 ...
     117.05999755859375 117.49199676513672 117.92400360107422 118.37000274658203 ...
     118.802001953125 119.24600219726562 119.67400360107422 120.11399841308594 ...
     120.552001953125 120.98799896240234 121.41999816894531 121.83999633789062 ...
     122.26399993896484 122.67400360107422 123.08999633789062 123.51000213623047 ...
     123.92800140380859 124.35600280761719 124.76599884033203 125.19000244140625 ...
     125.59999847412109 126.01999664306641 126.44400024414062 126.86599731445312 ...
     127.29399871826172 127.71199798583984 128.15400695800781 128.58200073242187 ...
     129.01400756835937 129.45199584960937 129.88600158691406 130.32000732421875 ...
     130.74400329589844 131.18400573730469 131.60600280761719 132.02999877929687 ...
     132.45799255371094 132.87800598144531 133.29800415039062 133.697998046875 ...
     134.10600280761719 134.51199340820312 134.91799926757812 135.33999633789063 ...
     135.75199890136719 136.18400573730469 136.61000061035156 137.04600524902344 ...
     137.48399353027344 137.91000366210937 138.34800720214844 138.77799987792969 ...
     139.21600341796875 139.64399719238281 140.08599853515625 140.52400207519531 ...
     140.94599914550781 141.37600708007812 141.79800415039062 142.22799682617187 ...
     142.63999938964844 143.052001953125 143.46200561523437 143.8699951171875 ...
     144.28999328613281 144.69999694824219 145.12600708007812 145.54800415039062 ...
     145.97200012207031 146.40400695800781 146.8280029296875 147.26600646972656 ...
     147.69400024414062 148.13999938964844 148.57600402832031 149.01199340820312 ...
     149.45599365234375 149.8800048828125 150.30799865722656 150.7239990234375 ...
     151.156005859375 151.57600402832031 151.99800109863281 152.41799926757813 ...
     152.82000732421875 153.23599243164062 153.64199829101562 154.0679931640625 ...
     154.49800109863281 154.92599487304688 155.3699951171875 155.802001953125 ...
     156.24800109863281 156.66999816894531 157.10400390625 157.53599548339844 ...
     157.95799255371094 158.38800048828125 158.80999755859375 159.24200439453125 ...
     159.65199279785156 160.08000183105469 160.51600646972656 160.94599914550781 ...
     161.3800048828125 161.78599548339844 162.19200134277344 162.58399963378906 ...
     162.98599243164062 163.40199279785156 163.8179931640625 164.25599670410156 ...
     164.67799377441406 165.10800170898437 165.52200317382812 165.94000244140625 ...
     166.37399291992187 166.80400085449219 167.24000549316406 167.66400146484375 ...
     168.09599304199219 168.52400207519531 168.94999694824219 169.3800048828125 ...
     169.80000305175781 170.23199462890625 170.64199829101562 171.05400085449219 ...
     171.45399475097656 171.85200500488281 172.26199340820313 172.66400146484375 ...
     173.08000183105469 173.5 173.91999816894531 174.35600280761719 174.78199768066406 ...
     175.21400451660156 175.63200378417969 176.06399536132812 176.49200439453125 ...
     176.92399597167969 177.36000061035156 177.77999877929687 178.22200012207031 ...
     178.65199279785156 179.08399963378906 179.50999450683594 179.92399597167969 ...
     180.33799743652344 180.73599243164062 181.14599609375 181.552001953125 ...
     181.97000122070312 182.39999389648437 182.83000183105469 183.27799987792969 ...
     183.70799255371094 184.14599609375 184.5679931640625 184.99600219726562 ...
     185.4320068359375 185.8699951171875 186.3179931640625 186.75199890136719 ...
     187.18800354003906 187.61799621582031 188.05999755859375 188.49800109863281 ...
     188.92799377441406 189.35400390625 189.75599670410156 190.1719970703125 ...
     190.58000183105469 191.00199890136719 191.42999267578125 191.85800170898437 ...
     192.302001953125 192.73199462890625 193.17399597167969 193.59800720214844 ...
     194.03199768066406 194.46000671386719 194.88600158691406 195.32400512695312 ...
     195.75 196.19200134277344 196.62399291992187 197.0679931640625 197.49400329589844 ...
     197.91799926757813 198.34599304199219 198.74200439453125 199.15400695800781 ...
     199.55999755859375 199.97000122070312 200.38800048828125 200.80400085449219 ...
     201.24200439453125 201.66799926757812 202.10600280761719 202.53599548339844 ...
     202.96400451660156 203.40400695800781 203.83599853515625 204.28199768066406 ...
     204.70599365234375 205.13999938964844 205.56599426269531 206 206.44599914550781 ...
     206.87800598144531 207.3179931640625 207.73399353027344 208.14799499511719 ...
     208.55000305175781 208.95599365234375 209.37199401855469 209.78199768066406 ...
     210.21000671386719 210.62600708007813 211.05000305175781 211.45599365234375 ...
     211.85800170898437 212.27799987792969 212.69200134277344 213.11799621582031 ...
     213.54400634765625 213.9739990234375 214.41600036621094 214.84800720214844 ...
     215.29200744628906 215.72599792480469 216.17399597167969 216.60400390625 ...
     217.02799987792969 217.43600463867187 217.83999633789063 218.25799560546875 ...
     218.66400146484375 219.08000183105469 219.5 219.91799926757812 220.35400390625 ...
     220.77799987792969 221.21200561523437 221.63600158691406 222.06399536132812 ...
     222.47799682617187 222.89799499511719 223.33599853515625 223.75599670410156 ...
     224.19599914550781 224.62800598144531 225.0679931640625 225.49400329589844 ...
     225.91400146484375 226.33599853515625 226.73599243164062 227.14999389648437 ...
     227.55999755859375 227.97200012207031 228.39199829101562 228.80599975585937 ...
     229.24000549316406 229.66200256347656 230.093994140625 230.52200317382812 ...
     230.94999694824219 231.38200378417969 231.80400085449219 232.24600219726562 ...
     232.6719970703125 233.10800170898437 233.54800415039062 233.99000549316406 ...
     234.4320068359375 234.86199951171875 235.29800415039062 235.71000671386719 ...
     236.13400268554688 236.55000305175781 236.97000122070312 237.39399719238281 ...
     237.81199645996094 238.24600219726562 238.66200256347656 239.09199523925781 ...
     239.52200317382812 239.947998046875 240.38200378417969 240.80799865722656 ...
     241.24400329589844 241.66799926757812 242.10400390625 242.53999328613281 ...
     242.98399353027344 243.4320068359375 243.87600708007812 244.31599426269531 ...
     244.72799682617187 245.15199279785156 245.57000732421875 245.99200439453125 ...
     246.42399597167969 246.84800720214844 247.27799987792969 247.68800354003906 ...
     248.05400085449219 248.36199951171875 248.62800598144531 248.91200256347656 ...
     249.18600463867187 249.406005859375 249.63200378417969 249.81599426269531 ...
     249.95599365234375 250.09199523925781 250.22200012207031 250.27400207519531 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.29400634765625 250.29400634765625 ...
     250.29400634765625 250.29400634765625 250.28799438476562 250.22599792480469 ...
     250.12800598144531 250.06199645996094 249.96800231933594 249.82200622558594 ...
     249.656005859375 249.47200012207031 249.302001953125 249.08799743652344 ...
     248.8800048828125 248.63999938964844 248.38400268554687 248.1300048828125 ...
     247.88800048828125 247.61799621582031 247.33399963378906 247.04800415039062 ...
     246.76199340820312 246.47000122070312 246.18600463867187 245.89199829101563 ...
     245.59199523925781 245.28999328613281 244.98199462890625 244.67599487304688 ...
     244.36000061035156 244.04200744628906 243.71800231933594 243.39199829101562 ...
     243.05400085449219 242.71000671386719 242.35600280761719 242.01199340820312 ...
     241.66200256347656 241.30400085449219 240.94000244140625 240.5679931640625 ...
     240.20199584960937 239.83999633789062 239.47200012207031 239.10000610351562 ...
     238.72999572753906 238.35200500488281 237.97200012207031 237.59599304199219 ...
     237.22000122070312 236.85200500488281 236.48199462890625 236.11000061035156 ...
     235.74400329589844 235.3800048828125 235.02799987792969 234.67999267578125 ...
     234.31199645996094 233.93400573730469 233.55799865722656 233.1719970703125 ...
     232.78199768066406 232.40199279785156 232.03599548339844 231.66200256347656 ...
     231.27200317382812 230.87199401855469 230.47200012207031 230.0679931640625 ...
     229.67399597167969 229.28999328613281 228.906005859375 228.52400207519531 ...
     228.13800048828125 227.76199340820312 227.38600158691406 227.00999450683594 ...
     226.63400268554687 226.25 225.88400268554687 225.52200317382812 225.15400695800781 ...
     224.77799987792969 224.39199829101562 224.00199890136719 223.61599731445312 ...
     223.23199462890625 222.85600280761719 222.47000122070312 222.0780029296875 ...
     221.69200134277344 221.29800415039062 220.89999389648437 220.50599670410156 ...
     220.11000061035156 219.7239990234375 219.33000183105469 218.93600463867187 ...
     218.54400634765625 218.14799499511719 217.75799560546875 217.37199401855469 ...
     217 216.64799499511719 216.29200744628906 215.92799377441406 215.56199645996094 ...
     215.17399597167969 214.78199768066406 214.406005859375 214.02200317382812 ...
     213.64799499511719 213.26600646972656 212.87800598144531 212.48199462890625 ...
     212.08399963378906 211.69200134277344 211.29600524902344 210.906005859375 ...
     210.51199340820313 210.13200378417969 209.75199890136719 209.36799621582031 ...
     208.98399353027344 208.60600280761719 208.21800231933594 207.8280029296875 ...
     207.45399475097656 207.09599304199219 206.74600219726562 206.37600708007813 ...
     205.99600219726562 205.61799621582031 205.23599243164062 204.85000610351562 ...
     204.45799255371094 204.06599426269531 203.66999816894531 203.27200317382812 ...
     202.87399291992187 202.47799682617187 202.08399963378906 201.70399475097656 ...
     201.32200622558594 200.93600463867187 200.54400634765625 200.15199279785156 ...
     199.76800537109375 199.38600158691406 199.00599670410156 198.6300048828125 ...
     198.25599670410156 197.89799499511719 197.54400634765625 197.17799377441406 ...
     196.80599975585937 196.4219970703125 196.03799438476562 195.656005859375 ...
     195.2760009765625 194.90199279785156 194.52000427246094 194.13400268554687 ...
     193.75 193.35600280761719 192.95399475097656 192.55799865722656 192.16000366210937 ...
     191.76199340820312 191.35800170898437 190.96600341796875 190.58399963378906 ...
     190.19400024414062 189.8179931640625 189.44400024414062 189.08200073242187 ...
     188.73199462890625 188.38200378417969 188.0260009765625 187.66200256347656 ...
     187.28199768066406 186.89399719238281 186.50399780273438 186.11000061035156 ...
     185.72200012207031 185.33000183105469 184.93800354003906 184.54600524902344 ...
     184.14199829101562 183.74200439453125 183.35000610351562 182.97200012207031 ...
     182.59599304199219 182.20599365234375 181.81399536132813 181.41999816894531 ...
     181.0260009765625 180.63800048828125 180.25399780273437 179.88600158691406 ...
     179.52200317382812 179.16799926757812 178.81599426269531 178.45199584960937 ...
     178.08000183105469 177.70599365234375 177.32600402832031 176.94400024414062 ...
     176.55999755859375 176.1719970703125 175.78999328613281 175.40400695800781 ...
     175.01400756835937 174.62199401855469 174.2239990234375 173.83200073242187 ...
     173.43800354003906 173.05000305175781 172.66600036621094 172.28399658203125 ...
     171.90199279785156 171.52400207519531 171.14399719238281 170.77000427246094 ...
     170.40400695800781 170.04600524902344 169.69200134277344 169.32600402832031 ...
     168.95199584960937 168.58000183105469 168.19999694824219 167.81599426269531 ...
     167.42399597167969 167.04200744628906 166.66400146484375 166.2760009765625 ...
     165.88600158691406 165.49200439453125 165.08799743652344 164.697998046875 ...
     164.31399536132812 163.93400573730469 163.55599975585938 163.16600036621094 ...
     162.77400207519531 162.37800598144531 161.98599243164062 161.60600280761719 ...
     161.24000549316406 160.8800048828125 160.51800537109375 160.14799499511719 ...
     159.7760009765625 159.38999938964844 159 158.6199951171875 158.23599243164062 ...
     157.84800720214844 157.45599365234375 157.0679931640625 156.6820068359375 ...
     156.28599548339844 155.89199829101562 155.5 155.11599731445312 154.73599243164063 ...
     154.34800720214844 153.96000671386719 153.57400512695312 153.17799377441406 ...
     152.78799438476562 152.39999389648437 152.0260009765625 151.66600036621094 ...
     151.30000305175781 150.92999267578125 150.5679931640625 150.197998046875 ...
     149.82400512695312 149.44400024414062 149.0679931640625 148.68800354003906 ...
     148.29600524902344 147.91200256347656 147.52400207519531 147.12399291992187 ...
     146.7239990234375 146.33999633789062 145.95399475097656 145.57000732421875 ...
     145.17799377441406 144.78399658203125 144.38600158691406 143.97799682617187 ...
     143.58200073242187 143.19999694824219 142.82600402832031 142.45199584960937 ...
     142.0780029296875 141.70199584960937 141.32000732421875 140.93400573730469 ...
     140.54600524902344 140.14799499511719 139.74800109863281 139.35200500488281 ...
     138.96200561523437 138.57200622558594 138.16999816894531 137.76400756835937 ...
     137.35800170898437 136.94999694824219 136.54800415039062 136.14399719238281 ...
     135.75399780273437 135.36199951171875 134.96400451660156 134.57000732421875 ...
     134.16999816894531 133.7760009765625 133.38600158691406 133.00799560546875 ...
     132.63200378417969 132.24600219726562 131.86000061035156 131.4739990234375 ...
     131.10400390625 130.73800659179687 130.36199951171875 129.97599792480469 ...
     129.58399963378906 129.17799377441406 128.77799987792969 128.38400268554687 ...
     127.98999786376953 127.59600067138672 127.18800354003906 126.77999877929687 ...
     126.37599945068359 125.97799682617187 125.58200073242187 125.17600250244141 ...
     124.77400207519531 124.38200378417969 123.99800109863281 123.62599945068359 ...
     123.24400329589844 122.85600280761719 122.46399688720703 122.07199859619141 ...
     121.68800354003906 121.30400085449219 120.91600036621094 120.52999877929687 ...
     120.12999725341797 119.73400115966797 119.33599853515625 118.94200134277344 ...
     118.54399871826172 118.13800048828125 117.73999786376953 117.34400177001953 ...
     116.94599914550781 116.552001953125 116.15200042724609 115.75399780273437 ...
     ];

D = [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ...
     1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
     0 0 0 0 0 0 0 0 0 0];

E = saveVarsMat.E; % <3000x1 double> too many elements

V = [0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1 0.11 0.12 0.13 0.14 ...
     0.15 0.16 0.17 0.18 0.19 0.2 0.21 0.22 0.23 0.24 0.25 0.26 0.27 0.28 ...
     0.29 0.3 0.31 0.32 0.33 0.34 0.35000000000000003 0.36 0.37 0.38 0.39 ...
     0.4 0.41000000000000003 0.42 0.43 0.44 0.45 0.46 0.47000000000000003 ...
     0.48 0.49 0.5 0.51 0.52 0.53 0.54 0.55 0.56 0.57000000000000006 0.58 ...
     0.59 0.6 0.61 0.62 0.63 0.64 0.65 0.66 0.67 0.68 0.69000000000000006 ...
     0.70000000000000007 0.71 0.72 0.73 0.74 0.75 0.76 0.77 0.78 0.79 0.8 ...
     0.81 0.82000000000000006 0.83000000000000007 0.84 0.85 0.86 0.87 0.88 ...
     0.89 0.9 0.91 0.92 0.93 0.94000000000000006 0.95000000000000007 0.96 ...
     0.97 0.98 0.99 1 1.01 1.02 1.03 1.04 1.05 1.06 1.07 1.08 1.09 1.1 ...
     1.11 1.12 1.1300000000000001 1.1400000000000001 1.1500000000000001 ...
     1.16 1.17 1.18 1.19 1.2 1.21 1.22 1.23 1.24 1.25 1.26 1.27 1.28 1.29 ...
     1.3 1.31 1.32 1.33 1.34 1.35 1.36 1.37 1.3800000000000001 1.3900000000000001 ...
     1.4000000000000001 1.41 1.42 1.43 1.44 1.45 1.46 1.47 1.48 1.49 1.5 ...
     1.51 1.52 1.53 1.54 1.55 1.56 1.57 1.58 1.59 1.6 1.61 1.62 1.6300000000000001 ...
     1.6400000000000001 1.6500000000000001 1.6600000000000001 1.67 1.68 ...
     1.69 1.7 1.71 1.72 1.73 1.74 1.75 1.76 1.77 1.78 1.79 1.8 1.81 1.82 ...
     1.83 1.84 1.85 1.86 1.87 1.8800000000000001 1.8900000000000001 1.9000000000000001 ...
     1.9100000000000001 1.92 1.93 1.94 1.95 1.96 1.97 1.98 1.99 2 2.0100000000000002 ...
     2.02 2.0300000000000002 2.04 2.05 2.06 2.07 2.08 2.09 2.1 2.11 2.12 ...
     2.13 2.14 2.15 2.16 2.17 2.18 2.19 2.2 2.21 2.22 2.23 2.24 2.25 2.2600000000000002 ...
     2.27 2.2800000000000002 2.29 2.3000000000000003 2.31 2.32 2.33 2.34 ...
     2.35 2.36 2.37 2.38 2.39 2.4 2.41 2.42 2.43 2.44 2.45 2.46 2.47 2.48 ...
     2.49 2.5 2.5100000000000002 2.52 2.5300000000000002 2.54 2.5500000000000003 ...
     2.56 2.57 2.58 2.59 2.6 2.61 2.62 2.63 2.64 2.65 2.66 2.67 2.68 2.69 ...
     2.7 2.71 2.72 2.73 2.74 2.75 2.7600000000000002 2.77 2.7800000000000002 ...
     2.79 2.8000000000000003 2.81 2.82 2.83 2.84 2.85 2.86 2.87 2.88 2.89 ...
     2.9 2.91 2.92 2.93 2.94 2.95 2.96 2.97 2.98 2.99 3 3.0100000000000002 ...
     3.02 3.0300000000000002 3.04 3.0500000000000003 3.06 3.0700000000000003 ...
     3.08 3.09 3.1 3.11 3.12 3.13 3.14 3.15 3.16 3.17 3.18 3.19 3.2 3.21 ...
     3.22 3.23 3.24 3.25 3.2600000000000002 3.27 3.2800000000000002 3.29 ...
     3.3000000000000003 3.31 3.3200000000000003 3.33 3.34 3.35 3.36 3.37 ...
     3.38 3.39 3.4 3.41 3.42 3.43 3.44 3.45 3.46 3.47 3.48 3.49 3.5 3.5100000000000002 ...
     3.52 3.5300000000000002 3.54 3.5500000000000003 3.56 3.5700000000000003 ...
     3.58 3.59 3.6 3.61 3.62 3.63 3.64 3.65 3.66 3.67 3.68 3.69 3.7 3.71 ...
     3.72 3.73 3.74 3.75 3.7600000000000002 3.77 3.7800000000000002 3.79 ...
     3.8000000000000003 3.81 3.8200000000000003 3.83 3.84 3.85 3.86 3.87 ...
     3.88 3.89 3.9 3.91 3.92 3.93 3.94 3.95 3.96 3.97 3.98 3.99 4 4.01 ...
     4.0200000000000005 4.03 4.04 4.05 4.0600000000000005 4.07 4.08 4.09 ...
     4.1 4.11 4.12 4.13 4.14 4.15 4.16 4.17 4.18 4.19 4.2 4.21 4.22 4.23 ...
     4.24 4.25 4.26 4.2700000000000005 4.28 4.29 4.3 4.3100000000000005 ...
     4.32 4.33 4.34 4.3500000000000005 4.36 4.37 4.38 4.39 4.4 4.41 4.42 ...
     4.43 4.44 4.45 4.46 4.47 4.48 4.49 4.5 4.51 4.5200000000000005 4.53 ...
     4.54 4.55 4.5600000000000005 4.57 4.58 4.59 4.6000000000000005 4.61 ...
     4.62 4.63 4.64 4.65 4.66 4.67 4.68 4.69 4.7 4.71 4.72 4.73 4.74 4.75 ...
     4.76 4.7700000000000005 4.78 4.79 4.8 4.8100000000000005 4.82 4.83 ...
     4.84 4.8500000000000005 4.86 4.87 4.88 4.89 4.9 4.91 4.92 4.93 4.94 ...
     4.95 4.96 4.97 4.98 4.99 5 5.01 5.0200000000000005 5.03 5.04 5.05 ...
     5.0600000000000005 5.07 5.08 5.09 5.1000000000000005 5.11 5.12 5.13 ...
     5.14 5.15 5.16 5.17 5.18 5.19 5.2 5.21 5.22 5.23 5.24 5.25 5.26 5.2700000000000005 ...
     5.28 5.29 5.3 5.3100000000000005 5.32 5.33 5.34 5.3500000000000005 ...
     5.36 5.37 5.38 5.39 5.4 5.41 5.42 5.43 5.44 5.45 5.46 5.47 5.48 5.49 ...
     5.5 5.51 5.5200000000000005 5.53 5.54 5.55 5.5600000000000005 5.57 ...
     5.58 5.59 5.6000000000000005 5.61 5.62 5.63 5.64 5.65 5.66 5.67 5.68 ...
     5.69 5.7 5.71 5.72 5.73 5.74 5.75 5.76 5.7700000000000005 5.78 5.79 ...
     5.8 5.8100000000000005 5.82 5.83 5.84 5.8500000000000005 5.86 5.87 ...
     5.88 5.89 5.9 5.91 5.92 5.93 5.94 5.95 5.96 5.97 5.98 5.99 6 6.01 ...
     6.0200000000000005 6.03 6.04 6.05 6.0600000000000005 6.07 6.08 6.09 ...
     6.1000000000000005 6.11 6.12 6.13 6.1400000000000006 6.15 6.16 6.17 ...
     6.18 6.19 6.2 6.21 6.22 6.23 6.24 6.25 6.26 6.2700000000000005 6.28 ...
     6.29 6.3 6.3100000000000005 6.32 6.33 6.34 6.3500000000000005 6.36 ...
     6.37 6.38 6.3900000000000006 6.4 6.41 6.42 6.43 6.44 6.45 6.46 6.47 ...
     6.48 6.49 6.5 6.51 6.5200000000000005 6.53 6.54 6.55 6.5600000000000005 ...
     6.57 6.58 6.59 6.6000000000000005 6.61 6.62 6.63 6.6400000000000006 ...
     6.65 6.66 6.67 6.68 6.69 6.7 6.71 6.72 6.73 6.74 6.75 6.76 6.7700000000000005 ...
     6.78 6.79 6.8 6.8100000000000005 6.82 6.83 6.84 6.8500000000000005 ...
     6.86 6.87 6.88 6.8900000000000006 6.9 6.91 6.92 6.93 6.94 6.95 6.96 ...
     6.97 6.98 6.99 7 7.01 7.0200000000000005 7.03 7.04 7.05 7.0600000000000005 ...
     7.07 7.08 7.09 7.1000000000000005 7.11 7.12 7.13 7.1400000000000006 ...
     7.15 7.16 7.17 7.18 7.19 7.2 7.21 7.22 7.23 7.24 7.25 7.26 7.2700000000000005 ...
     7.28 7.29 7.3 7.3100000000000005 7.32 7.33 7.34 7.3500000000000005 ...
     7.36 7.37 7.38 7.3900000000000006 7.4 7.41 7.42 7.43 7.44 7.45 7.46 ...
     7.47 7.48 7.49 7.5 7.51 7.5200000000000005 7.53 7.54 7.55 7.5600000000000005 ...
     7.57 7.58 7.59 7.6000000000000005 7.61 7.62 7.63 7.6400000000000006 ...
     7.65 7.66 7.67 7.68 7.69 7.7 7.71 7.72 7.73 7.74 7.75 7.76 7.7700000000000005 ...
     7.78 7.79 7.8 7.8100000000000005 7.82 7.83 7.84 7.8500000000000005 ...
     7.86 7.87 7.88 7.8900000000000006 7.9 7.91 7.92 7.9300000000000006 ...
     7.94 7.95 7.96 7.97 7.98 7.99 8 8.01 8.02 8.03 8.0400000000000009 ...
     8.05 8.06 8.07 8.08 8.09 8.1 8.11 8.120000000000001 8.13 8.14 8.15 ...
     8.16 8.17 8.18 8.19 8.2 8.21 8.22 8.23 8.24 8.25 8.26 8.27 8.28 8.2900000000000009 ...
     8.3 8.31 8.32 8.33 8.34 8.35 8.36 8.370000000000001 8.38 8.39 8.4 ...
     8.41 8.42 8.43 8.44 8.45 8.46 8.47 8.48 8.49 8.5 8.51 8.52 8.53 8.5400000000000009 ...
     8.55 8.56 8.57 8.58 8.59 8.6 8.61 8.620000000000001 8.63 8.64 8.65 ...
     8.66 8.67 8.68 8.69 8.7000000000000011 8.71 8.72 8.73 8.74 8.75 8.76 ...
     8.77 8.78 8.7900000000000009 8.8 8.81 8.82 8.83 8.84 8.85 8.86 8.870000000000001 ...
     8.88 8.89 8.9 8.91 8.92 8.93 8.94 8.9500000000000011 8.96 8.97 8.98 ...
     8.99 9 9.01 9.02 9.03 9.0400000000000009 9.05 9.06 9.07 9.08 9.09 ...
     9.1 9.11 9.120000000000001 9.13 9.14 9.15 9.16 9.17 9.18 9.19 9.2000000000000011 ...
     9.21 9.22 9.23 9.24 9.25 9.26 9.27 9.28 9.2900000000000009 9.3 9.31 ...
     9.32 9.33 9.34 9.35 9.36 9.370000000000001 9.38 9.39 9.4 9.41 9.42 ...
     9.43 9.44 9.4500000000000011 9.46 9.47 9.48 9.49 9.5 9.51 9.52 9.53 ...
     9.5400000000000009 9.55 9.56 9.57 9.58 9.59 9.6 9.61 9.620000000000001 ...
     9.63 9.64 9.65 9.66 9.67 9.68 9.69 9.7000000000000011 9.71 9.72 9.73 ...
     9.74 9.75 9.76 9.77 9.78 9.7900000000000009 9.8 9.81 9.82 9.83 9.84 ...
     9.85 9.86 9.870000000000001 9.88 9.89 9.9 9.91 9.92 9.93 9.94 9.9500000000000011 ...
     9.96 9.97 9.98 9.99 10];

e = 1001;

flag = 's';

i = 3001;

j = 3002;

n = 1001;

q = 3000;

serial_com = saveVarsMat.serial_com; % <1x1 serial> unsupported class

u = 1000;

x = 1001;

y = 1001;

z = 3003;

clear saveVarsMat;
