#include <list>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


//std::list<int> listOfInts;
//listOfInts.push_back(1);



int main(){
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::visualization::PCLVisualizer viewer;
  std::list<pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> > colors;

  pcl::PCDReader reader;
  int num_files = 20;

  std::string name = "planes/plane";
  std:: string id_name = "cloud_id";

  //create list with ramdom colors
  for (int i=0; i<num_files; i++){
    int c1 = rand() % 256;
    int c2 = rand() % 256;
    int c3 = rand() % 256;
    colors.push_back(pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>(cloud,c1,c2,c3));
  }


  std::list<pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> >::iterator it=colors.begin();

  for (int i=0; i<num_files,it != colors.end(); i++, ++it){
    std::string filename = name + boost::lexical_cast<std::string>(i) + ".pcd";
    std::string id = id_name + boost::lexical_cast<std::string>(i);
    std::cout << filename <<endl;

    reader.read (filename, *cloud);
    viewer.addPointCloud<pcl::PointXYZ>(cloud,*it, id);

  }


  viewer.spin();


}
