//
//  settingViewController.swift
//  Sekans
//
//  Created by 张雨姗 on 12/12/16.
//  Copyright © 2016 Zhang Yushan. All rights reserved.
//

import UIKit

class SettingViewController: UIViewController {

    @IBOutlet weak var bodySlider: UISlider!
    @IBOutlet weak var bodySizeLabel: UILabel!
    @IBOutlet weak var headColorControl: UISegmentedControl!
    @IBOutlet weak var backgroundColorControl: UISegmentedControl!
    
    var viewController : ViewController?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // initialize bodySlider action
        bodySlider.addTarget(self, action: #selector(SettingViewController.sizeChanged), for: .valueChanged)
        
        // initialize reference
        let myWindow = UIApplication.shared.keyWindow
        let root = myWindow?.rootViewController
        let rootChild = root?.childViewControllers
        viewController = rootChild?[0] as? ViewController
    }
    
    override func viewWillAppear(_ animated: Bool) {
        // initialize variable
        let bodySize = UserDefaults.standard.value(forKey: "bodySize") as! Float
        bodySizeLabel.text = String(bodySize)
        bodySlider.setValue(bodySize, animated: false)
        headColorControl.selectedSegmentIndex = UserDefaults.standard.value(forKey: "headColor") as! Int
        backgroundColorControl.selectedSegmentIndex = UserDefaults.standard.value(forKey: "backgroundColor") as! Int
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func sizeChanged(){
        // calculate new body size
        let step:Float = 5
        let value = round(bodySlider.value/step) * step
        
        // update value
        bodySlider.setValue(value, animated: false)
        bodySizeLabel.text = String(value)
        
        UserDefaults.standard.setValue(Float(value), forKey: "bodySize")
        UserDefaults.standard.synchronize()
    }
    
    @IBAction func headColorChanged(_ sender: UISegmentedControl) {
        if sender.selectedSegmentIndex == 0 {
            viewController?.headColor = UIColor.red
            UserDefaults.standard.setValue(Int(0), forKey: "headColor")
        }else if sender.selectedSegmentIndex == 1{
             viewController?.headColor = UIColor.blue
             UserDefaults.standard.setValue(Int(1), forKey: "headColor")
        }else{
            viewController?.headColor = UIColor.green
            UserDefaults.standard.setValue(Int(2), forKey: "headColor")
        }
        UserDefaults.standard.synchronize()
    }
    
    @IBAction func backgroundColorChanged(_ sender: UISegmentedControl) {
        if sender.selectedSegmentIndex == 0{
            viewController?.sekan?.backgroundColor = UIColor.white
            UserDefaults.standard.setValue(Int(0), forKey: "backgroundColor")
        }else{ viewController?.sekan?.backgroundColor = UIColor.gray
            UserDefaults.standard.setValue(Int(1), forKey: "backgroundColor")
        }
        UserDefaults.standard.synchronize()
    }
    
}
