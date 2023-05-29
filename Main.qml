/*
 *  JS 资源导入
 *
 *  如果使用特殊的 .pragma 标记这些库,变成共享库
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-29
 *
*/

//Main.qml

import QtQuick
import "factorial.js" as FactorialCalculator


Row{

    Calculator{}
    Calculator{ input:6 }

    TapHandler{
        onTapped:
            console.log(FactorialCalculator.factorialCallCount())
    }
}
