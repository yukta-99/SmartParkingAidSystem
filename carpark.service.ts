/*
*Project Name: Smart Parking Aid System
*Author List: Rutwik Patel, Pranav Garg
*Filename: carpark.service.ts
*Functions: get_status(), return_data()
*Global Variables: interface ' Placedata ', string array 'vacancydata'
*/



import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { tap } from 'rxjs/operators';


interface Placedata {
  slot1: string;
  slot2: string;
  slot3: string;
}

@Injectable({
  providedIn: 'root'
})
export class CarparkService {
  private vacancydata: string[] = [
    'Data',
    'Data',
    'Data'
  ];

  constructor(private http: HttpClient) { }

  /*
  *get_status() requests data of car park one from firebase realtime database and stores it in the string array ' vacancydata '
  *Placedata is used to specify the data format in which we would like to map the response data coming from the firebase realtime database
  */
  get_status(msg: string) {
    return this.http.get<{ [key: string]: Placedata }>('https://parking-cloud-1315b.firebaseio.com/car-park-one.json').pipe(tap(
      resData => {
        for (const key in resData) {
          if (true) {
            this.vacancydata[0] = resData[key].slot1;
            this.vacancydata[1] = resData[key].slot2;
            this.vacancydata[2] = resData[key].slot3;
          }
        }
      }
    ));
  }

  /*
  *return_data() sends the string array ' vacancydata ' when it is called
  */
  return_data() {
    return this.vacancydata;
  }
}
