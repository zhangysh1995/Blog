//
//  machineSnake.swift
//  Sekans
//
//  Created by 张雨姗 on 12/4/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import Foundation
import UIKit

class machineSnake: Snake{
    
    override init(headColor: UIColor = UIColor.red , bodyColor: UIColor = UIColor.black){
        super.init(headColor: headColor, bodyColor: bodyColor)
        
        let headPoint = CGPoint(x: 0,y: 0)
        self.body_.append(headPoint)
        setHeadPoint(head: headPoint)
        
    }
}
