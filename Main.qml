/*
 * A example : ListView
 *
 *一个 ListView 有:
 一个 model property :定义将被显示的数据;
 一个 delegate property :定义了数据应如何被显示;
 *
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-14
 *
 *
 *   内部组件 ( 环境 ) 的创建环境:如果内部组件是通过其复合组件对象
     来引用加载的,此时会同时存在复合组件的环境和内部组件的环境,
     并且前者是后者的父环境,或者称为创建环境 (creation context) 。
*/

//在独立的创建环境中创建内部组件对象
import QtQuick

ListView{
    width: 200
    height: 100
    A{id:my}
    spacing: 2
    model: 3
    delegate: my.mycomponent
}













