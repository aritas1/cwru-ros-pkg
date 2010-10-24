#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <tf/transform_listener.h>
#include <image_geometry/pinhole_camera_model.h>
#include <cv_bridge/CvBridge.h>
#include <string>
#include <vector>
#include "cwru_features.h"



int main(int argc, char *argv[]){
  
  ros::init(argc, argv, "vision_test");
  
  int num_features=47;
  //feature 67
  double values [47*8]= {-0.966349, -0.405281, 0.064822, 268.930817, 443.817657, -0.093732, 0.370350, 0.924151,
-0.895354, -0.399351, 0.071162, 271.107819, 441.664124, -0.090260, 0.367389, 0.925677,
-0.810393, -0.391493, 0.079745, 274.075958, 439.106903, -0.085485, 0.363869, 0.927519,
-0.730937, -0.385444, 0.078977, 277.355743, 436.505280, -0.080172, 0.360272, 0.929396,
-0.650481, -0.379401, 0.084800, 280.097748, 433.804932, -0.075735, 0.356477, 0.931230,
-0.577286, -0.372185, 0.086676, 282.487396, 430.831421, -0.071878, 0.352238, 0.933146,
-0.461755, -0.362555, 0.094718, 286.028564, 428.254913, -0.066058, 0.348599, 0.934941,
-0.382106, -0.357679, 0.098511, 288.262177, 425.337463, -0.062421, 0.344377, 0.936754,
-0.309751, -0.352343, 0.103191, 290.813690, 422.809296, -0.058219, 0.340717, 0.938362,
-0.231150, -0.343937, 0.107666, 292.679993, 419.209320, -0.055190, 0.335409, 0.940455,
-0.141312, -0.336670, 0.108928, 294.545044, 415.891235, -0.052140, 0.330488, 0.942369,
-0.068268, -0.331762, 0.108285, 296.317688, 414.558807, -0.049177, 0.328532, 0.943212,
0.053626, -0.318698, 0.107241, 296.616516, 409.572144, -0.048805, 0.320989, 0.945824,
0.130626, -0.310307, 0.106136, 296.352234, 406.335785, -0.049340, 0.316049, 0.947459,
0.210250, -0.301223, 0.109780, 297.246521, 403.906952, -0.047881, 0.312353, 0.948759,
0.281762, -0.293479, 0.109196, 297.298889, 401.091675, -0.047862, 0.308025, 0.950174,
0.357791, -0.281831, 0.111632, 298.074066, 398.774323, -0.046596, 0.304466, 0.951383,
0.403635, -0.277170, 0.108704, 297.534821, 395.833374, -0.047589, 0.299893, 0.952785,
0.472212, -0.269635, 0.110344, 297.470001, 392.579468, -0.047779, 0.294823, 0.954357,
0.562073, -0.261162, 0.106048, 296.927551, 389.534515, -0.048783, 0.290044, 0.955769,
0.630856, -0.253346, 0.104887, 295.692993, 386.295410, -0.050982, 0.284920, 0.957195,
0.750811, -0.241486, 0.097431, 291.076172, 381.412476, -0.059049, 0.277075, 0.959032,
0.828548, -0.234565, 0.090814, 286.797119, 378.526489, -0.066494, 0.272360, 0.959895,
0.920659, -0.226196, 0.081079, 281.556091, 374.425323, -0.075642, 0.265638, 0.961101,
1.007215, -0.219293, 0.075456, 276.511444, 369.440338, -0.084498, 0.257450, 0.962590,
1.118385, -0.210514, 0.061772, 267.457886, 361.364746, -0.100387, 0.244018, 0.964561,
1.190184, -0.207793, 0.054043, 261.616364, 355.897675, -0.110659, 0.234848, 0.965713,
1.321213, -0.204395, 0.038498, 253.557877, 347.690216, -0.124863, 0.220995, 0.967249,
1.393014, -0.200855, 0.029660, 248.311539, 341.334869, -0.134155, 0.210230, 0.968404,
1.465402, -0.199781, 0.017817, 241.765701, 334.891663, -0.145664, 0.199186, 0.969075,
1.546032, -0.198258, 0.007851, 235.321381, 328.820953, -0.156957, 0.188708, 0.969409,
1.631797, -0.197496, -0.000456, 227.801590, 322.481384, -0.170054, 0.177672, 0.969285,
1.713100, -0.197063, -0.005268, 221.198318, 315.819305, -0.181566, 0.166093, 0.969251,
1.782137, -0.197988, -0.012841, 215.140137, 308.368591, -0.192151, 0.153166, 0.969339,
1.864569, -0.201101, -0.020470, 209.813049, 300.029785, -0.201501, 0.138720, 0.969615,
1.969657, -0.207773, -0.030840, 201.734558, 287.822845, -0.215550, 0.117482, 0.969400,
2.089694, -0.211523, -0.033577, 195.366180, 274.036041, -0.226676, 0.093538, 0.969468,
2.209596, -0.214400, -0.036403, 187.811340, 260.511414, -0.239581, 0.069960, 0.968352,
2.451935, -0.200894, -0.060495, 179.518677, 234.329651, -0.253673, 0.024491, 0.966980,
2.567164, -0.206820, -0.057141, 175.590500, 215.412003, -0.260121, -0.008280, 0.965541,
2.680531, -0.212838, -0.047925, 170.191467, 194.914993, -0.268589, -0.043598, 0.962268,
2.802651, -0.219850, -0.042753, 162.990967, 172.561661, -0.279428, -0.081669, 0.956687,
2.915399, -0.226880, -0.042667, 155.927185, 146.680115, -0.289262, -0.125035, 0.949049,
3.030397, -0.234221, -0.040734, 149.954483, 121.625145, -0.296734, -0.166120, 0.940400,
3.109431, -0.236850, -0.038953, 144.713623, 100.913437, -0.302866, -0.199225, 0.931977,
3.183901, -0.239720, -0.038701, 138.498993, 78.143524, -0.309744, -0.234570, 0.921431,
3.297500, -0.242915, -0.033147, 127.576042, 41.058441, -0.320870, -0.289503, 0.901793};
  
  printf("starting\n");
  FeatureManager testing;
  
  for(int i=0;i<num_features*8;i+=8){
    testing.add( RawFeature(values[i],values[i+1],values[i+2],cv::Point2d(values[i+3],values[i+4]),cv::Point3d(values[i+5],values[i+6],values[i+7])));
  //  testing.raw_features[i/8].print();
  }
  
  double yaw=0.8 * 3.14159/180;
  double pitch=-34.38 * 3.14159/180;
  double roll=-3.67 * 3.14159/180;
  
  
  cv::Mat camera_frame_offset=cv::Mat::zeros(3,1,CV_64F);
  camera_frame_offset.at<double>(0,0)=.06;
  
  testing.raw_features[0].calcRay( yaw, pitch,roll);
  
  //testing.raw_features[0].print();

  cv::Point3d error=testing.calc_least_squares_position(yaw, pitch,roll, camera_frame_offset);
  
  printf("error %f %f %f\n",error.x,error.y,error.z);
  printf("stopping\n");
  return 0;
}
