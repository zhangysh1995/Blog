//
//  resultViewController.swift
//  Sekans
//
//  Created by 张雨姗 on 12/10/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import UIKit

class ResultViewController: UIViewController {
    var snake: Snake?
    
    @IBOutlet weak var resultLabel: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

        if let loser = snake{
            if loser is playerSnake{ resultLabel.text = "Computer win!"}
            else{ resultLabel.text = "You win!"}
        }else { resultLabel.text = "No Result Yet"}
    }

    override func viewWillDisappear(_ animated: Bool) {
        snake = nil
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

}
