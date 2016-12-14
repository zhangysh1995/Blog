//
//  ViewController.swift
//  Sekans
//
//  Created by 张雨姗 on 12/2/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var sekan: SekanView?
    @IBOutlet weak var leftButton: UIButton!
    @IBOutlet weak var rightButton: UIButton!
    @IBOutlet weak var upButton: UIButton!
    @IBOutlet weak var downButton: UIButton!
    @IBOutlet weak var playButton: UIButton!

    var size : CGFloat = 25
    var headColor = UIColor.red
    
    var machine : machineSnake?
    var player : playerSnake?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // hide statusBar
        var prefersStatusBarHidden:Bool{
            get{return true}
        }
        setNeedsStatusBarAppearanceUpdate()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        
        // retrieve default values
        if let newSize = UserDefaults.standard.value(forKey: "bodySize") as? Float{
            size = CGFloat(newSize)
        }
        player = playerSnake(headPoint: CGPoint(x: CGFloat(375)-size, y: CGFloat(425)-size), headColor: headColor)
        machine = machineSnake(headColor: headColor)
        
        //initialize control of Sekan
        let subview = self.view.subviews
        let stackView = subview[0] as! UIStackView
        sekan = stackView.subviews[0] as? SekanView
        
        initGame()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "showResult" {
            if let resultViewController = segue.destination as? ResultViewController{
                resultViewController.snake = sender as? Snake}
        }
    }

    func initGame(){
        sekan!.player = player
        sekan!.machine = machine
        sekan!.size = size
        sekan!.setNeedsDisplay()
    }
    
    func endGame(looser: Snake){
        // show Results
        performSegue(withIdentifier: "showResult", sender: looser)
    }
    
    
    // MARK: left

    @IBAction func playerGoLeft(_ sender: UIButton) {
        goLeft(snake: player!)
    }

    func goLeft(snake: Snake) {
        let newX = snake.getHeadPoint().x - size
        let newY = snake.getHeadPoint().y
        updateSnake(X: newX, Y: newY, snake: snake)
    }
    
    
    // MARK: right

    @IBAction func playerGoRight(_ sender: UIButton) {
        goRight(snake: player!)
    }
    
    func goRight(snake: Snake) {
        let newX = snake.getHeadPoint().x + size
        let newY = snake.getHeadPoint().y
        updateSnake(X: newX, Y: newY, snake: snake)
    }
    
    
    // MARK: up
    
    @IBAction func playerGoUp(_ sender: UIButton) {
        goUp(snake: player!)
    }
    
    func goUp(snake: Snake) {
        let newX = snake.getHeadPoint().x
        let newY = snake.getHeadPoint().y - size
        updateSnake(X: newX, Y: newY, snake: snake)
    }
    
    
    // MARK: right

    @IBAction func playerGoDown(_ sender: UIButton) {
        goDown(snake: player!)
    }
    
    func goDown(snake: Snake) {
        let newX = snake.getHeadPoint().x
        let newY = snake.getHeadPoint().y + size
        updateSnake(X: newX, Y: newY, snake: snake)
    }
    
    
    // MARK: helper
    
    func updateSnake(X: CGFloat, Y: CGFloat, snake: Snake){
        // point is in view's bounds
        if  checkBoundary(X: X, Y: Y) {
            // new winner
            if checkWinner(X: X, Y: Y) { endGame(looser: snake)}
            // continue
            else{
                snake.appendBodyPoint(head: CGPoint(x: X, y: Y))
                sekan!.setNeedsDisplay()
                // move computer's snake
                if snake is playerSnake{ machineMove()}
            }
        }else{ endGame(looser: snake)}
    }
    
    // cheack if point is out of view's bounds
    func checkBoundary(X: CGFloat, Y: CGFloat)->Bool{
        if  X>=0&&X<=350&&Y>=0&&Y<=405 { return true}
        else{ return false}
    }
    
    // check if there is winner
    func checkWinner(X: CGFloat, Y: CGFloat)->Bool{
        let points = player!.getBodyPoint() + machine!.getBodyPoint()
        
        // run into one point is already occupied
        for point in points{
            if point.x == X && point.y == Y { return true}
        }
        return false
    }

    
    // generate direction for machine snake
    // machine snake avoid run into 
    func machineMove(){
           srandom(UInt32(time(nil)))
        
        var points = [CGFloat]()
        points.append(contentsOf: machineGoLeft())
        points.append(contentsOf: machineGoRight())
        points.append(contentsOf: machineGoUp())
        points.append(contentsOf: machineDown())
        
        // shuffle order of possible direction
        var index = [0, 2, 4, 6]
        index.sort(by: {a, b in
            return  a+b > Int(arc4random()%10)
        })
        
        // choose one from directions
        for i in index{
            let x = points[i]
            let y = points[i+1]
            if checkBoundary(X: x, Y: y) {
                if !checkWinner(X: x, Y: y) {
                    machine!.appendBodyPoint(head: CGPoint(x: x, y: y))
                    sekan!.setNeedsDisplay()
                    return
                }
            }
        }
        endGame(looser: machine!)
    }
    
    func machineGoLeft()->[CGFloat]{
        let newX = machine!.getHeadPoint().x - size
        let newY = machine!.getHeadPoint().y
        return [newX, newY]
        
    }
    
    func machineGoRight()->[CGFloat]{
        let newX = machine!.getHeadPoint().x + size
        let newY = machine!.getHeadPoint().y
        return [newX, newY]
    }
    
    func machineGoUp()->[CGFloat]{
        let newX = machine!.getHeadPoint().x
        let newY = machine!.getHeadPoint().y - size
        return [newX, newY]
        
    }
    
    func machineDown()->[CGFloat]{
        let newX = machine!.getHeadPoint().x
        let newY = machine!.getHeadPoint().y + size
        return [newX, newY]
        
    }
    
}

