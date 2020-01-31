import { Component, OnInit } from '@angular/core';
import { CarparkService } from 'src/app/carpark/carpark.service';



@Component({
  selector: 'app-parkingslots',
  templateUrl: './parkingslots.page.html',
  styleUrls: ['./parkingslots.page.scss'],
})
export class ParkingslotsPage implements OnInit {
  lam: string[] = [];

  constructor(private some: CarparkService) { }

  ngOnInit() {
    this.get_info('efasfeas');
    this.whats();
  }
  get_info(msg: string) {
    this.some.get_status('edfasf').subscribe();
  }
  whats() {
    this.lam = this.some.retire();
  }
}
