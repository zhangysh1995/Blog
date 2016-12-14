//
//  sekanView.swift
//  Sekans
//
//  Created by 张雨姗 on 12/2/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import UIKit

class SekanView: UIView {

    // initialize two snakes
    var machine : machineSnake?
    var player : playerSnake?
    
    var size : CGFloat = 25
    
    // Mark: draw
    override func draw(_ rect: CGRect) {
        if let newBackGroundColor = UserDefaults.standard.value(forKey: "backgroundColor") as? UIColor{
            self.backgroundColor = newBackGroundColor
        }
        
        let context = UIGraphicsGetCurrentContext()
        
        // draw snake body
        let mSnake = drawSnake(newSnake: machine!)
        let pSnake = drawSnake(newSnake: player!)
        context!.addRects(mSnake)
        context!.addRects(pSnake)
        context!.fillPath()
        
        // draw snake head
        let mHead = machine!.getHeadPoint()
        let pHead = player!.getHeadPoint()
        
        machine!.getHeadColor().set()
        UIBezierPath(rect: CGRect(x: mHead.x, y: mHead.y, width: size, height: size)).fill()
        player!.getHeadColor().set()
        UIBezierPath(rect: CGRect(x: pHead.x, y: pHead.y, width: size, height: size)).fill()
    }
    
    // get rectangles of snake body
    func drawSnake(newSnake: Snake)->[CGRect]{
        let body = newSnake.getBodyPoint()
        var rectangles = [CGRect]()
        
        for point in body{
            if point == body.last!{break}
            
            let rect = CGRect(x: point.x, y: point.y, width: size, height: size)
            rectangles.append(rect)
        }
        return rectangles
    }    
}
