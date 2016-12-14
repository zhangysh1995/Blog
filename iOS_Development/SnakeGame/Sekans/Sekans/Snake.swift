//
//  snake.swift
//  Sekans
//
//  Created by 张雨姗 on 12/4/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import Foundation
import UIKit

class Snake: NSObject{
    
    var headPoint_ : CGPoint?
    var body_ = [CGPoint]()
    
    var headColor_: UIColor?
    var bodyColor_: UIColor?

    
    init(headColor: UIColor = UIColor.red , bodyColor: UIColor = UIColor.black){
        self.headColor_ = headColor
        self.bodyColor_ = bodyColor
    }
    
    
    // MARK: getters
    func getHeadPoint()->CGPoint{
        return self.body_.last!
    }
    
    func getBodyPoint()->[CGPoint]{
        return self.body_
    }
    
    func getHeadColor()-> UIColor{
        return self.headColor_!
    }
    
    func getBodyColor()->UIColor{
        return self.bodyColor_!
    }
    
    
    // MARK: setters
    func appendBodyPoint(head: CGPoint){
        body_.append(head)
        setHeadPoint(head: head)
    }
    func setHeadPoint(head: CGPoint){
        self.headPoint_ = head
        
    }
    
    func setHeadColor(headColor: UIColor){
        self.headColor_ = headColor
    }
    
    func setBodyColor(bodyColor: UIColor){
        self.bodyColor_ = bodyColor
    }
    
    // MARK: moves

}

