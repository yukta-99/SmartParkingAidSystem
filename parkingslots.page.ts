/*
*Project Name: Smart Parking Aid System
*Author List: Rutwik Patel, Pranav Garg
*Filename: parkingslots.page.ts
*Functions: initiate_data_request(), update_vacancy_data()
*Global Variables: slotdata
*/

import { Component, OnInit } from '@angular/core';
// Injecting the carpark.service.ts
import { CarparkService } from 'src/app/carpark/carpark.service';
@Component({
  selector: 'app-parkingslots',
  templateUrl: './parkingslots.page.html',
  styleUrls: ['./parkingslots.page.scss'],
})
export class ParkingslotsPage implements OnInit {
  slotdata: string[] = [];

  constructor(private ServiceInstance: CarparkService) { }
  /*
  *ngOnInit() is generated automatically when you generate a page in angular, the function ngOnInit() runs exactly once
  *when the app starts
  */
  ngOnInit() {
    this.initiate_data_request('Dummy String');
    this.update_vacancy_data();
  }

  /*
  *initiate_data_request() uses the service instance of the carpark.service.ts inorder to call the function get_status()
  *of carpark.service.ts which initialises the http.get request to get the slot vacancy data from the firebase real time database
  */
  initiate_data_request(msg: string) {
    this.ServiceInstance.get_status('Dummy String').subscribe();
  }

  /*
  *update_vacancy_data() uses the service instance of the carpark.service.ts inorder to call the function return_data()
  *of carpark.service.ts to update the slotdata string array which displays the vacancy status
  */
  update_vacancy_data() {
    this.slotdata = this.ServiceInstance.return_data();
  }
}
