#include <iostream>
#include "boost/filesystem.hpp"
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


using namespace boost::filesystem;

int main()
{
    //point cloud object
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    //visualizator object
    pcl::visualization::PCLVisualizer viewer;
    //reader object
    pcl::PCDReader reader;
    //assuming the segmented clouds are at the current directory
    path p (".");
    directory_iterator end_itr;

    // cycle through the directory
    for (directory_iterator itr(p); itr != end_itr; ++itr){
        // assign current file name to current_file and echo it out to the console.
        std::string file = itr->path().string();
        std::cout << file << std::endl;
        boost::filesystem::path fe = itr->path().extension();
        if(fe.string()==".pcd"){
            std::cout << fe.string() << std::endl;
            //set random colors to the colors vector
            int c1 = rand() % 256;
            int c2 = rand() % 256;
            int c3 = rand() % 256;
            reader.read (file, *cloud);
            viewer.addPointCloud<pcl::PointXYZ>(cloud,
              pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>(cloud,c1,c2,c3)
              ,file);
          }
    }

    viewer.spin();
}
