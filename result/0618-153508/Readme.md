# Daily Evaluation 18/06 - 15:35:08
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 14/23 :  60%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                                                       | Stdout                                     |
| :---------- | :---------- | :------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------- |
| dimension   | 4/4 :  100% |                                                                                                                                                    |                                            |
| first_pixel | 0/5 :  0%   | First Pixel 64x64 : 255,0,0<br>First Pixel Red : 255,0,0<br>First Pixel Green : 0,255,0<br>First Pixel Blue : 0,0,255<br>First Pixel 1 2 3 : 1,2,3 | Image chargée : 64 x 64, 3 canaux          |
                                                                                                                                                                                   Couleur du premier pixel :                  
                                                                                                                                                                                   R = 255                                     
                                                                                                                                                                                   G = 0                                       
                                                                                                                                                                                   B = 0<br>Image chargée : 8 x 8, …           
                                                                                                                                                                                   Couleur du premier pixel :                  
                                                                                                                                                                                   R = 255                                     
                                                                                                                                                                                   G = 0                                       
                                                                                                                                                                                   B = 0<br>Image chargée : 8 x 8, 3 canaux    
                                                                                                                                                                                   Couleur du premier pixel :                  
                                                                                                                                                                                   R = 0                                       
                                                                                                                                                                                   G = 255                                     
                                                                                                                                                                                   B = 0<br>Image chargée : 8 x 8, 3 canaux    
                                                                                                                                                                                   Couleur du premier pixel :                  
                                                                                                                                                                                   R = 0                                       
                                                                                                                                                                                   G = 0                                       
                                                                                                                                                                                   B = 255<br>Image chargée : 8 x 8, 3 canaux  
                                                                                                                                                                                   Couleur du premier pixel :                  
                                                                                                                                                                                   R = 1                                       
                                                                                                                                                                                   G = 2                                       
                                                                                                                                                                                   B = 3                                       
| tenth_pixel | 5/5 :  100% |                                                                                                                                                    |                                            |
| second_line | 5/5 :  100% |                                                                                                                                                    |                                            |
| print_pixel | 0/4 :  0%   | Print Pixel (0,0) : 0,0,0<br>Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0                             | <br><br><br>                               |

# Milestone  statistiques
Score : 22/26 :  84%
## Detail by Feature
| Feature         | Score       | Missed tests                                                                       | Stdout       |
| :-------------- | :---------- | :--------------------------------------------------------------------------------- | :----------- |
| max_pixel       | 4/4 :  100% |                                                                                    |              |
| min_pixel       | 0/4 :  0%   | Min Pixel black 8x8<br>Min Pixel white 8x8<br>Min Pixel at 6 5<br>Min Pixel at 3 4 | <br><br><br> |
| min_component R | 3/3 :  100% |                                                                                    |              |
| min_component G | 3/3 :  100% |                                                                                    |              |
| min_component B | 3/3 :  100% |                                                                                    |              |
| max_component R | 3/3 :  100% |                                                                                    |              |
| max_component G | 3/3 :  100% |                                                                                    |              |
| max_component B | 3/3 :  100% |                                                                                    |              |

# Milestone  colors
Score : 30/35 :  85%
## Detail by Feature
| Feature              | Score       | Missed tests                                                                                                                                         | Stdout           |
| :------------------- | :---------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100% |                                                                                                                                                      |                  |
| color_blue           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_green          | 5/5 :  100% |                                                                                                                                                      |                  |
| color_gray           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_invert         | 5/5 :  100% |                                                                                                                                                      |                  |
| color_gray_luminance | 5/5 :  100% |                                                                                                                                                      |                  |
| color_desaturate     | 0/5 :  0%   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br> |

# Milestone  transform
Score : 0/15 :  0%
## Detail by Feature
| Feature           | Score     | Missed tests                                                   | Stdout   |
| :---------------- | :-------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| rotate_acw        | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| mirror_horizontal | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

