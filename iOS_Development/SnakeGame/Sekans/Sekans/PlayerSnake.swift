//
//  playerSnake.swift
//  Sekans
//
//  Created by 张雨姗 on 12/4/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import Foundation
import UIKit

class playerSnake: Snake{
    
    init(headPoint :CGPoint = CGPoint(x: 350, y:400),headColor: UIColor = UIColor.red , bodyColor: UIColor = UIColor.black){
        super.init(headColor: headColor, bodyColor: bodyColor)
        
        self.body_.append(headPoint)
        setHeadPoint(head: headPoint)
    }
}
