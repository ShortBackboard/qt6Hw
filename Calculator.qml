//MyButton.qml


import QtQuick
import QtQuick.Controls
import "factorial.js" as FactorialCalculator

//This Js resource is only
//ever loaded once by the engine
//even if multiple instance of
//Calculator.qml are created


Text{
    width: 500
    height: 100
    property int input: 5 //默认为5
    text: "The factorial of " + input + " is:"
        + FactorialCalculator.factorial(input)
}




















