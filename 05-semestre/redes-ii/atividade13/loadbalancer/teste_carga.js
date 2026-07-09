import http from 'k6/http';
import { check } from 'k6';

export const options = {
  vus: 10,         // 10 usuários virtuais simultâneos
  iterations: 1000 // total de 1000 requisições
};

export default function () {
  const res = http.get('http://nginx/api/dados');
  check(res, { 'status was 200': (r) => r.status == 200 });
}