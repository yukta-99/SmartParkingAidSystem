import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Status } from 'src/app/home/status.model';
import { tap, take, map, delay, switchMap } from 'rxjs/operators';


interface Placedata {
  slot1: string;
  slot2: string;
  slot3: string;
}

@Injectable({
  providedIn: 'root'
})
export class CarparkService {
  private fan: string[] = [
    'Data',
    'Data',
    'Data'
  ];

  constructor(private http: HttpClient) { }
  get_status(msg: string) {
    return this.http.get<{ [key: string]: Placedata }>('https://parking-cloud-1315b.firebaseio.com/car-park-one.json').pipe(tap(
      resData => {
        for (const key in resData) {
          if (true) {
            // this.fan.push(resData[key].slot1, resData[key].slot2, resData[key].slot3);
            this.fan[0] = resData[key].slot1;
            this.fan[1] = resData[key].slot2;
            this.fan[2] = resData[key].slot3;
            // console.log(this.fan);
          }
        }
      }
    ));
  }
  retire() {
    return this.fan;
  }
}
